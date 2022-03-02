
#include "directoryVariables.h"

char* PARENT_DIR = "/etc/";
char* BASE_DIR ;
char* DOWNLOADED_FILES_DIR ;
char* CATEGORIES_DIR ;
char* LOGS_DIR ;
char* FINAL_LISTS_DIR ;
char* CONFIG_SETTINGS_FILE ;


void init_directoryVariables(){
PARENT_DIR = "/etc/";
BASE_DIR =  getPathToFile (PARENT_DIR, "yads_config");
DOWNLOADED_FILES_DIR = getPathToFile (BASE_DIR, "downloaded_files");
CATEGORIES_DIR = getPathToFile (BASE_DIR, "categories");
LOGS_DIR = getPathToFile (BASE_DIR, "logs");
FINAL_LISTS_DIR = getPathToFile (BASE_DIR, "final_lists");
CONFIG_SETTINGS_FILE = getPathToFile (BASE_DIR, "config_settings");
}


