#include <stdlib.h>

#include "libs/FileIO/libfileio.h"
#include "init.h"


void createInitDirStructure(char* root_directory){

    char* pathToYads_config = createFolderIfItDoesntExist("yads_config", root_directory);

    if (pathToYads_config == NULL){
        printf("Error!!! creating yads_config folder\n");
        exit(1);
    }
    char* pathToDownloaded_files = createFolderIfItDoesntExist("downloaded_files", pathToYads_config);
    
    char* pathToCategories = createFolderIfItDoesntExist("categories", pathToYads_config);
    
    char* pathToLogs = createFolderIfItDoesntExist("logs", pathToYads_config);
    
    char* pathToFinal_lists = createFolderIfItDoesntExist("final_lists", pathToYads_config);
   
    createFileIfItDoesntExist("config_settings", pathToYads_config);

    free (pathToYads_config);
    free (pathToDownloaded_files);
    free (pathToCategories);
    free (pathToLogs);
    free (pathToFinal_lists);

}
