#ifndef LIB_URL_HANDLING_H
#define LIB_URL_HANDLING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#include <curl/curl.h>
#if !CURL_AT_LEAST_VERSION(7, 62, 0)
#error "This URL Praser requires curl 7.62.0 or later. :Issue at urlHandling.c."
#endif

extern const char* DEFAULT_PROTOCOL;

struct url_struct {
    char *protocol;
    char *domain;
    char *path;
    char *query;
    };

typedef struct url_struct URL_DATA;

void freeURLStruct(URL_DATA *url); // frees the memory allocated for the url struct
int parseURL(URL_DATA *url, char *url_string); // returns 0 on success, 1 on failure (invalid url) 
URL_DATA* newURLStruct(); // returns a new URL_DATA struct after allocating memory with NULL values
char* toString(URL_DATA* url_struct); // returns a string representation of the url
int isValidDomainString(char *url_domain_string); // returns 0 if the url is valid, 1 if it is not


#endif // LIB_URL_HANDLING_H
