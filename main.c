#include <stdio.h>
#include <string.h>

#include "init.h"
// get user arguments in int main
int main(int argc, char *argv[])
{
    // check if there are any arguments
    // if there are no arguments, print error message
    if (argc == 1)
    {
        printf("Error: No arguments were given.\n");
        return 1;
    }
    else {

        if (strcmp(argv[1] , "init") == 0){

            printf("init is called\n");
        
            if (argc ==2){

                createInitDirStructure("/etc/");
                return 0;
            }
            else{
                printf("Error: too many arguments\n");
                return 1;
            }
        }

        else {
            printf("Error: Invalid arguments.\n");
            return 1;
        }


    }
   
}

