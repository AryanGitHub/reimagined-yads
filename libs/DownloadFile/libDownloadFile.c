#include "libDownloadFile.h"

FILE* getFilePointer (char* filePath) {

    FILE* file  = fopen (filePath, "w");
    if (file == NULL){
        fprintf(stderr , "ERROR: fopen() cannot initialize the file pointer.\n");
        exit(EXIT_FAILURE); 
        return NULL;
    }
    return file;
    }

int closeFilePointer (FILE* file) {
        int close = fclose(file);
        if (close == EOF) {
            fprintf(stderr,"ERROR: fclose() not successfully closed the file.\n");
            return EXIT_FAILURE;
            }

        else { 
           return EXIT_SUCCESS;
           }

}
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream){
    size_t written;
    written =fwrite(ptr, size,nmemb, (FILE*)stream);
    return written;
}
int downloadFile (char* URL, char* filePath){

   FILE* getFilePointer (char* filePath);
   

    CURL *curl = curl_easy_init(); 
    if (curl){
    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_URL, URL); 
    /* URL is redirected, so we tell libcurl to follow redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);


    FILE* file = getFilePointer(filePath);


        /* send all data to this function  */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        /* we pass our 'chunk' struct to the callback function */
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)file);
    
    res = curl_easy_perform(curl);
    //Check for errors 
    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
     }
    

    closeFilePointer(file);
   
    curl_easy_cleanup(curl);
 
    curl_global_cleanup();
    return 0;

    }
    return EXIT_FAILURE;
}
