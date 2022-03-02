
#include "createCategory.h"

void createNewCategory(char* name_of_category, char* path_to_category)
{

    char* pathToCategoryDir = createFolderIfItDoesntExist(name_of_category, path_to_category);

    if (pathToCategoryDir == NULL)
    {
        printf("Error: Could not create catagory\n");
        return;
    }
    char* path_to_list_of_lists = createFileIfItDoesntExist("list_of_lists.txt", pathToCategoryDir);   
    char* path_to_user_added_list_of_urls =  createFileIfItDoesntExist("user_added_list_of_urls.txt", pathToCategoryDir);
    char* pathToDownloadListsDir = createFolderIfItDoesntExist("downloadLists", pathToCategoryDir);
    char* path_to_hashlists_of_downloads =  createFileIfItDoesntExist("hashlists_of_downloads.txt", pathToCategoryDir);
    char* path_to_map_url_to_files =  createFileIfItDoesntExist("map_url_to_files.txt", pathToCategoryDir);
    char* path_to_category_struct_data = createFileIfItDoesntExist("category_struct_data.txt", pathToCategoryDir);

    category_struct newCategory;
    newCategory = newCategoryStruct(&newCategory, name_of_category, 0);//add uid later
    structWriter(&newCategory, path_to_category_struct_data, sizeof(category_struct));  

    
    free(pathToCategoryDir);
    free(pathToDownloadListsDir);
    free(path_to_list_of_lists);
    free(path_to_user_added_list_of_urls);
    free(path_to_hashlists_of_downloads);
    free(path_to_map_url_to_files);
    free(path_to_category_struct_data);

}

