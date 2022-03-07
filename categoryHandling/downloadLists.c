#include "downloadLists.h"


int downloadListsFromListOfLists(char* categoryName){
    
    int downloadFilesFromList (char** listOfURLs ,int numberofURLs, char* pathToFolder , char* categoryName);

    int successfulDownloads = 0;
    int numberOfLists;
    char** listOfLists = NULL;
    getListOfLists(&listOfLists, &numberOfLists,categoryName);
    printf("number of urls read from file: %d\n",numberOfLists);
    char* pathToFile = getPathToDownload_Lists_Dir(categoryName);
    successfulDownloads = downloadFilesFromList(listOfLists, numberOfLists, pathToFile, categoryName);
    free(pathToFile);
    free(listOfLists);

    return successfulDownloads;
}


int downloadFilesFromList (char** listOfURLs ,int numberofURLs, char* pathToFolder , char* categoryName){
    int successfulDownloads = 0;

    char* pathToMapFile = getPathToMap_URL_To_Files(categoryName);
    FILE* fp = fopen(pathToMapFile,"a+");
    
    if(fp == NULL){
        printf("Error opening file %s\n",getPathToMap_URL_To_Files(categoryName));
        return 0;
    }
    for(int i=0;i<numberofURLs;i++){
        char filename[500];
        snprintf(filename, sizeof(filename), "File%d.txt", i+1);

        char* pathToFile = getPathToFile(filename, pathToFolder);
        int status = downloadFile(*(listOfURLs+i), pathToFile);

        free(pathToFile);
        
        if (status ==EXIT_FAILURE) strcpy(filename, "NULL");
        else successfulDownloads++;

        fprintf(fp,"%s - %s\n",*(listOfURLs+i),filename);
    }

    fclose (fp);
    free(pathToMapFile);

    return successfulDownloads;
}
