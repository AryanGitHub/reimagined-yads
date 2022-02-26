#ifndef CATEGORY_STRUCT_HANDLING_H
#define CATEGORY_STRUCT_HANDLING_H


#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>



typedef struct category_struct {
uint32_t category_unique_ID;
char category_name[500];
time_t created_unix_time, last_modified_unix_time, last_download_unix_time;
}category_struct;


int structWriter (void* data, char* filename, size_t size);
category_struct* structReader (category_struct* category_struct_pointer,char* filename); 



#endif // CATEGORY_STRUCT_HANDLING_H
