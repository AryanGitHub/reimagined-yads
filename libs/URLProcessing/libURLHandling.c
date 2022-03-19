#include "libURLHandling.h"

const char* DEFAULT_PROTOCOL = "http";


void freeURLStruct(URL_DATA *url){

    if (url->protocol != NULL)
        curl_free(url->protocol); 
    if (url->domain != NULL)
        curl_free(url->domain);
    if (url->path != NULL)
        curl_free(url->path);
    if (url->query != NULL)
        curl_free(url->query);

}

URL_DATA* url_struct_init(URL_DATA* url){

    url->protocol = NULL;
    url->domain = NULL;
    url->path = NULL;
    url->query = NULL;
    return url;
}

URL_DATA* newURLStruct(){

    URL_DATA* url_struct_init(URL_DATA* url);

    URL_DATA* url = (URL_DATA*)malloc(sizeof(URL_DATA));
    if (url == NULL)
        return NULL;
    url_struct_init(url);
    return url;
}



char* toString(URL_DATA* url){

    if (url == NULL){
        printf("URL is NULL\n");
        return NULL;
    }

    int url_string_size = 0;
    if (url->protocol != NULL)
        url_string_size += strlen(url->protocol);
    if (url->domain != NULL)
        url_string_size += strlen(url->domain);
    if (url->path != NULL)
        url_string_size += strlen(url->path);
    if (url->query != NULL)
        url_string_size += strlen(url->query);

    char* url_string = (char*)malloc(sizeof(char)*(url_string_size)+4);
     

    url_string[0] = '\0';
    
    if (url->protocol != NULL)
        strcat(url_string, url->protocol);
    strcat(url_string, "://");
    if (url->domain != NULL)
        strcat(url_string, url->domain);
    if (url->path != NULL)
        strcat(url_string, url->path);
    if (url->query != NULL)
        strcat(url_string, url->query);

    return url_string;
}

int parseURL(URL_DATA *url_struct, char *url_string){

    if (url_struct ==NULL || url_string == NULL){
    printf("Error: url_struct or url_string is NULL\n");
     return 1;
    }

    CURLU *h; 
    CURLUcode uc;

    h = curl_url();
    if (h == NULL){
        printf("Error: curl_url() failed\n");
        return 1;
    }

    char* isHavingProtocol = strchr(url_string, ':');
    if (isHavingProtocol == NULL){
        url_struct->protocol = NULL;
        //add default protocol
        char *url_string_temp = (char *)malloc(sizeof(char)*(strlen(url_string)+strlen(DEFAULT_PROTOCOL)+4));
        
        if (url_string_temp == NULL){
            printf("Error: malloc failed\n");
            return 1;
        }
        url_string_temp[0] = '\0';
        strcat(url_string_temp, DEFAULT_PROTOCOL);
        strcat(url_string_temp, "://");
        strcat(url_string_temp, url_string);

        url_string = url_string_temp;

    }

    uc = curl_url_set(h, CURLUPART_URL, url_string , 0);
    if (uc != CURLUE_OK){
        printf("Error: curl_url_set() failed\n");
        return 1;
    }
    
    uc = curl_url_get(h,CURLUPART_SCHEME , &(url_struct->protocol), 0);
    if (uc != CURLUE_OK){
        printf("Error: curl_url_get(), protocol parsing failed\n");
        freeURLStruct(url_struct);
        curl_url_cleanup(h);
        return 1;
    }

    uc = curl_url_get(h,CURLUPART_HOST, &(url_struct->domain), 0);
    if (uc != CURLUE_OK){
        printf("Error: curl_url_get(), domain parsing failed\n");
        freeURLStruct(url_struct);
        curl_url_cleanup(h);
        return 1;
    }

    int isValidDomain = isValidDomainString(url_struct->domain);
    if (isValidDomain == 1){
        printf("Error: domain is not valid\n");
        freeURLStruct(url_struct);
        curl_url_cleanup(h);
        return 1;
    }


    uc = curl_url_get(h,CURLUPART_PATH  , &(url_struct->path), 0);
    if (uc != CURLUE_OK){
        printf("Error: curl_url_get(), path parsing failed\n");
        freeURLStruct(url_struct);
        curl_url_cleanup(h);
        return 1;
    }
    
    char* isHavingQuery = strchr(url_string, '?');
    if (isHavingQuery == NULL){
        url_struct->query = NULL;
    }
    else{
        uc = curl_url_get(h,CURLUPART_QUERY, &(url_struct->query), 0);
        if (uc != CURLUE_OK){
            printf("Error: curl_url_get(), query parsing failed\n");
            freeURLStruct(url_struct);
            curl_url_cleanup(h);
            return 1;
        }
    }
    curl_url_cleanup(h);
    return 0;

}  

int isValidDomainString(char *url_domain_string){

    if (url_domain_string == NULL){
        printf("Error: url_domain_string is NULL\n");
        return 1;
    }

    regex_t regex;
   int value = regcomp(&regex, "^([^-]+[A-Za-z0-9-]{1,63}+[^-])[.]([a-zA-Z0-9]{2,6})$", REG_EXTENDED);
    if (value != 0){
        printf("Error: regcomp() failed\n");
        return 1;
    }

    value = regexec(&regex, url_domain_string, 0, NULL, 0);
    if (value != 0){
        printf("Error: regexec() failed\n");
        return 1;
    }
    printf("%s ",url_domain_string);
    regfree(&regex);
    return 0;
}
