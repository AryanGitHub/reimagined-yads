#include "listOfListsHandling.h"

int addListOfLists(char **listOfURLs, int numberOfURLs, char* categoryName){
    char* pathToFile = getPathToCategoryList_Of_List_File(categoryName);
    int numberOfURLsAppended = appendListToFile(pathToFile, listOfURLs, numberOfURLs);
    free (pathToFile);
    return numberOfURLsAppended;
}

char** getListOfLists (char ***listOfURLs, int *numberOfURLs, char* categoryName){
    
    char* pathToFile = getPathToCategoryList_Of_List_File(categoryName);
    printf("list of lists file path is %s\n",pathToFile); 
    getListFromFile(listOfURLs, numberOfURLs, pathToFile);

    free (pathToFile);
    return *listOfURLs;
    
}
