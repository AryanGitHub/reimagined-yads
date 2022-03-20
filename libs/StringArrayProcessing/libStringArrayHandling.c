#include "libStringArrayHandling.h"

void freeStringArray(char** stringArray, int size)
{
    for (int i = size-1; i >= 0; i--)
    {
        free(stringArray[i]);
        stringArray[i] = NULL;
    }

}


