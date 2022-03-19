#ifndef CATEGORY_FILES_PATH_H
#define CATEGORY_FILES_PATH_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FileIO/libFileIO.h"
#include "directoryVariables.h"



char* getPathToCategoryDir(char* categoryName);
char* getPathToCategoryList_Of_List_File(char* categoryName);
char* getPathToUser_Added_List_Of_URLs(char* categoryName);
char* getPathToMap_URL_To_Files(char* categoryName);
char* getPathToCategory_Struct_Data(char* categoryName);
char* getPathToHashlists_Of_Downloads(char* categoryName);
char* getPathToDownload_Lists_Dir(char* categoryName);
char* getPathToCompiled_List_Of_URLs(char* categoryName);




#endif // CATEGORY_FILES_PATH_H
