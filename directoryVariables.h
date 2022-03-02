#ifndef DIRECTORY_VARIABLES_H
#define DIRECTORY_VARIABLES_H

#include "FileIO/libFileIO.h"


static char* PARENT_DIR = "/etc/";
static char* BASE_DIR ;
static char* DOWNLOADED_FILES_DIR ;
static char* CATEGORIES_DIR ;
static char* LOGS_DIR ;
static char* FINAL_LISTS_DIR ;
static char* CONFIG_SETTINGS_FILE ;

void init_directoryVariables();

#endif // DIRECTORY_VARIABLES_H
