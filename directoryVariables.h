#ifndef DIRECTORY_VARIABLES_H
#define DIRECTORY_VARIABLES_H

#include "FileIO/libFileIO.h"


char* PARENT_DIR = "/etc/";
char* BASE_DIR ;
char* DOWNLOADED_FILES_DIR ;
char* CATEGORIES_DIR ;
char* LOGS_DIR ;
char* FINAL_LISTS_DIR ;
char* CONFIG_SETTINGS_FILE ;

void init_directoryVariables();

#endif // DIRECTORY_VARIABLES_H
