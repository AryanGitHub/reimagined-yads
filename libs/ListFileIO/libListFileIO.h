#ifndef LIB_LIST_FILE_IO_H
#define LIB_LIST_FILE_IO_H


#include <stdio.h>
#include <stdlib.h>

int appendListToFile(char *filePath, char** list, int numberOfItems);
char** getListFromFile (char ***list, int *numberOfItems , char *filePath);

#endif // LIB_LIST_FILE_IO_H
