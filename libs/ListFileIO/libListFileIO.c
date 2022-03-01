#include "libListFileIO.h"

int appendListToFile(char *filePath, char** list, int numberOfItems){
    FILE *fp;
    int i;
    fp = fopen(filePath, "a+");
    if(fp == NULL){
        printf("Error opening file!\n");
        return -1;
    }
    for(i =0; i < numberOfItems; i++){
        fprintf(fp, "%s\n", list[i]);
    }
    fclose(fp);
    return i;
}
