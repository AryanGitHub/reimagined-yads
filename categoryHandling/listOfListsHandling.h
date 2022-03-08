#ifndef LIST_OF_LISTS_HANDLING_H
#define LIST_OF_LISTS_HANDLING_H


#include "ListFileIO/libListFileIO.h"
#include "categoryFilesPath.h"

int addListOfLists(char **listOfURLs, int numberOfURLs , char* categoryName );
char** getListOfLists (char ***listOfURLs, int *numberOfURLs, char* categoryName);

#endif //LIST_OF_LISTS_HANDLING_H
