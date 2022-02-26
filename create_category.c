#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "libs/FileIO/libfileio.h"
#include "create_category.h"

void createNewCategory(char* name_of_catagory, char* path_to_catagory)
{

    char* pathToCatagoryDir = createFolderIfItDoesntExist(name_of_catagory, path_to_catagory);
    createFileIfItDoesntExist("list_of_lists.txt", pathToCatagoryDir);   
    createFileIfItDoesntExist("user_added_list_of_url.txt", pathToCatagoryDir);
    char* pathToDownloadListsDir = createFolderIfItDoesntExist("downloadLists", pathToCatagoryDir);
    createFileIfItDoesntExist("hashlists_of_downloads.txt", pathToCatagoryDir);
    createFileIfItDoesntExist("map_url_to_files.txt", pathToCatagoryDir);
    free(pathToCatagoryDir);
    free(pathToDownloadListsDir);
}

