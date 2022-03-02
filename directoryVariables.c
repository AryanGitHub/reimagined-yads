
#include "directoryVariables.h"

char* PARENT_DIR ;
char* BASE_DIR ;
char* DOWNLOADED_FILES_DIR ;
char* CATEGORIES_DIR ;
char* LOGS_DIR ;
char* FINAL_LISTS_DIR ;
char* CONFIG_SETTINGS_FILE ;


void init_directoryVariables(){
PARENT_DIR = "/etc";
BASE_DIR =  getPathToFile ("yads_config",PARENT_DIR);
DOWNLOADED_FILES_DIR = getPathToFile ("downloaded_files",BASE_DIR);
CATEGORIES_DIR = getPathToFile ("categories",BASE_DIR);
LOGS_DIR = getPathToFile ("logs",BASE_DIR);
FINAL_LISTS_DIR = getPathToFile ("final_lists",BASE_DIR);
CONFIG_SETTINGS_FILE = getPathToFile ("config_settings",BASE_DIR);
}


