#ifndef DIRECTORY_VARIABLES_H
#define DIRECTORY_VARIABLES_H

#include "FileIO/libFileIO.h"

const char* PARENT_DIR = "/etc/";
const char* BASE_DIR = getPathToFile (PARENT_DIR, "yads_config");
const char* DOWNLOADED_FILES_DIR = getPathToFile (BASE_DIR, "downloaded_files");
const char* CATEGORIES_DIR = getPathToFile (BASE_DIR, "categories");
const char* LOGS_DIR = getPathToFile (BASE_DIR, "logs");
const char* FINAL_LISTS_DIR = getPathToFile (BASE_DIR, "final_lists");
const char* CONFIG_SETTINGS_FILE = getPathToFile (BASE_DIR, "config_settings");

#endif // DIRECTORY_VARIABLES_H
