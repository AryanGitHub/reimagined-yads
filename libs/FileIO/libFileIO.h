#ifndef LIB_FILE_IO_H
#define LIB_FILE_IO_H

int isFileExists (char* path);
int isDirExists (char* path);
char** getContents(char*** names, int* size,char *address);
char* getPathToFile(char* name_of_file, char* path_to_directory);
char* createFileIfItDoesntExist(char* name_of_file , char* path_to_file);
char* createFolderIfItDoesntExist(char* name_of_folder, char* path_to_folder);
#endif // LIB_FILE_IO_H
