
#include "categoryStructHandling.h"


int structWriter (void* data, char* filename, size_t size) {
    FILE* fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }
    size_t written = fwrite(data, size, 1, fp);
    fclose(fp);
    return !written;
}


category_struct* structReader (category_struct* category_struct_pointer,char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }
    
    unsigned int read = fread(category_struct_pointer, sizeof(category_struct), 1, fp);
    fclose(fp);
    if (read!=1){
     printf("Error in reading the struct, total number of struct read is  %u\n", read);
    
     return NULL;
    }
    return category_struct_pointer;
}
  






