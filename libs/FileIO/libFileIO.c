#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

#include "libFileIO.h"


int isFileExists(char *path){
    
    if(!access(path, F_OK )){
        return 1;
    }else{
        return 0;
    }
}


int isDirExists (char *path)
{
    DIR *dirptr;

    if ((dirptr = opendir (path)) != NULL) {
            closedir (dirptr); 
            return 1;
    }
    else {
        return 0;    
    }
}


char** getContents(char*** names, int* size,char *address)
{
    struct dirent *dp;
    DIR *dir = opendir(address);

    if (dir==NULL) return NULL;

    *names = (char**)malloc((*size)*sizeof(char*));
    int i = 0;

    while ((dp = readdir(dir)) != NULL)
    {

        //printf("%s\n", dp->d_name);
        int len  = strlen(dp->d_name);
        char *name = (char*)malloc(len+1);
        //strcpy_s(name, len+1,dp->d_name);
        strcpy(name, dp->d_name);
        (*names)[i] = name;
        i++;
        if (i>=(*size)){
            (*size)*=2;
            *names = (char**)realloc(*names,(*size));
        }

    }
    
    *size = i;
    *names = (char**)realloc(*names,(*size));
    closedir(dir);
    return *names;
}



char* getPathToFile(char* name_of_file, char* path_to_directory)
{
    int len = strlen(path_to_directory) + strlen(name_of_file) + 2;
    char* path = malloc(sizeof(char) * len);
    strcpy(path, path_to_directory);
    strcat(path, "/");
    strcat(path, name_of_file);
    return path;
}

char* createFileIfItDoesntExist(char* name_of_file , char* path_to_dir){
    char* pathToFile = getPathToFile(name_of_file, path_to_dir);
    if (isFileExists (pathToFile)){
        printf("%s file already exists\n",name_of_file);
        return NULL;
    }
    else {
        // creating the file
        FILE* file = fopen(pathToFile, "w");
        if (file == NULL) {
            printf("%s file not created\n",name_of_file);
            fclose(file);
            return NULL;
        }
        else {
            printf("%s file created\n",name_of_file);
            fclose(file);
            return pathToFile;
        }
        
    }
}

char* createFolderIfItDoesntExist(char* name_of_folder, char* path_to_folder){
    char* pathToFolder = getPathToFile(name_of_folder, path_to_folder);
    if (isDirExists (pathToFolder)){
        printf("%s directory already exists\n",name_of_folder);
        return pathToFolder;
    }
    else {
        // creating the folder
        int folderStatus = mkdir (pathToFolder, 0777);

        if (!folderStatus) {
            printf("%s directory created\n",name_of_folder);
            return pathToFolder;
        }
        else {
            printf("%s directory not created\n",name_of_folder);
            return NULL;
        }
        
    }
}


