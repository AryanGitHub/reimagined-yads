#include <stdio.h>
#include <string.h>

#include "init.h"
#include "categoryHandling/createCategory.h"
#include "categoryHandling/userAddedListOfURLsHandling.h"
#include "directoryVariables.h"

extern char* PARENT_DIR;
extern char* CATEGORIES_DIR;
// get user arguments in int main
int main(int argc, char *argv[])
{
    init_directoryVariables();
    // check if there are any arguments
    // if there are no arguments, print error message
    if (argc == 1)
    {
        printf("Error: No arguments given.\n");
        return 1;
    }
    else {

        if (strcmp(argv[1] , "init") == 0){

            printf("init called\n");
        
            if (argc ==2){

                createInitDirStructure(PARENT_DIR);
                return 0;
            }
            else{
                printf("too many arguments\n");
                return 1;
            }
        }

        else if (strcmp(argv[1] , "newCategory") == 0){

            printf("newCategory called\n");
        
            if (argc ==3){

             createNewCategory(argv[2],CATEGORIES_DIR);  //argv[2] is the name of the category
                
                return 0;
            }
            else{
                printf("Error: Invalid arguments.\n");
                return 1;
            }
        }


        else if (strcmp(argv[1] , "addURLsToBlacklist") == 0){

            printf("addURLsToBlacklist called\n");
        
            if (argc > 3){
                int numberOfURLs = argc - 3;
                addListOfURLsToBlackList(&argv[3],  numberOfURLs, argv[2]);
                return 0;
            }
            else{
                printf("Error: Invalid arguments.\n");
                return 1;
            }
        } 


        else {
            printf("Error: Invalid arguments.\n");
            return 1;
        }



    }
   
}

