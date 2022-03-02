#include "userAddedListOfURLsHandling.h"

int addListOfURLsToBlackList(char **listOfURLs, int numberOfURLs, char* categoryName){
    char* pathToFile = getPathToUser_Added_List_Of_URLs(categoryName);
    int numberOfURLsAppended = appendListToFile(pathToFile, listOfURLs, numberOfURLs);
    free (pathToFile);
    return numberOfURLsAppended;
}

