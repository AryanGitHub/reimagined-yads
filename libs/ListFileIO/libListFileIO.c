#include "libListFileIO.h"
//#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int appendListToFile(char *filePath, char** list, int numberOfItems){
    FILE *fp;
    int i;
    fp = fopen(filePath, "a+");
    if(fp == NULL){
        printf("Error opening file!\n");
        return -1;
    }
    for(i =0; i < numberOfItems; i++){
        fprintf(fp, "%s\n", list[i]);
    }
    fclose(fp);
    return i;
}

char** getListFromFile (char ***list, int *numberOfItems , char *filePath){
    FILE* fp = fopen (filePath, "r");

    if (fp == NULL){
        printf("Error in opening file %s\n", filePath);
        return NULL;
    }

    if ((*numberOfItems) < 0 || *list == NULL){
        *numberOfItems = 1;
        *list = (char**)malloc((sizeof(char**)) * (*numberOfItems)); //allocate memory for the list
    }

    int counter = 0;

    while (!feof(fp)){
        if (counter >= (*numberOfItems)){
            (*numberOfItems) *= 2;
            *list = (char**) realloc(*list, (*numberOfItems) * (sizeof(char**)) );

        }   

        *(*list + counter) = NULL;
        size_t str_len = 0;
        getline((*list + counter) , &str_len , fp);
        (*(*list + counter))[strlen(*(*list + counter)) - 1] = '\0';
        
        //printf("strlen: %u\n", strlen(*(*list + counter)) );
        
        if (strlen(*(*list + counter)) == 0){
            continue;
        }
        
        //printf("%s\n", *(*list + counter));
        
        counter++;
    }

    *numberOfItems = counter;
    *list = (char**) realloc(*list, (sizeof(char**)) * (*numberOfItems) );
    return *list;

}
