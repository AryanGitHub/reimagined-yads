#include "categoryFilesPath.h"

char* getPathToCategoryDir(char* categoryName) {
    char* path = getPathToFile (categoryName, CATEGORIES_DIR);
    return path;
}

char* getPathToCategoryList_Of_List_File(char* categoryName) {
    char* pathToParentDir = getPathToCategoryDir(categoryName);
    char* path = getPathToFile ("list_of_lists.txt", pathToParentDir);
    free(pathToParentDir);
    return path;
}

char* getPathToUser_Added_List_Of_URLs(char* categoryName) {
    char* pathToParentDir = getPathToCategoryDir(categoryName);
    char* path = getPathToFile ("user_added_list_of_urls.txt", pathToParentDir);
    free(pathToParentDir);
    return path;
}

char* getPathToMap_URL_To_Files(char* categoryName) {
    char* pathToParentDir = getPathToCategoryDir(categoryName);
    char* path = getPathToFile ("map_url_to_files.txt", pathToParentDir);
    free(pathToParentDir);
    return path;
}

char* getPathToCategory_Struct_Data(char* categoryName) {
    char* pathToParentDir = getPathToCategoryDir(categoryName);
    char* path = getPathToFile ("category_struct_data.txt", pathToParentDir);
    free(pathToParentDir);
    return path;
}

char* getPathToHashlists_Of_Downloads(char* categoryName) {
    char* pathToParentDir = getPathToCategoryDir(categoryName);
    char* path = getPathToFile ("hashlists_of_downloads.txt", pathToParentDir);
    free(pathToParentDir);
    return path;
}

char* getPathToDownload_Lists_Dir(char* categoryName) {
    char* pathToParentDir = getPathToCategoryDir(categoryName);
    char* path = getPathToFile ("downloadLists", pathToParentDir);
    free(pathToParentDir);
    return path;
}






