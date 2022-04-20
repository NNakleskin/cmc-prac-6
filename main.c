#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "handler.h"
#include <string.h>


int count = 0;


int main(int argc, char **argv)
{
    short status = 0;
    if(argc < 2)
    {
        printf("Key not found\n");
        return 0;
    }
    for(int i = 1; i < argc; i++)
    {
        if(!strcmp(argv[i], "-help"))
        {
            help();
        }
        if(!strcmp(argv[i], "-test-f1"))
        {
            if(argc == 3)
            {
                test_f1(strtod(argv[2], NULL));		
            }
            else
            {
                puts("Argument not found");
            }
        }
        if(!strcmp(argv[i], "-test-f2"))
        {
            if(argc == 3)
            {
                test_f2(strtod(argv[2], NULL));		
            }
            else
            {
                puts("Argument not found");
            }
        }
        if(!strcmp(argv[i], "-test-f3"))
        {
            if(argc == 3)
            {
                test_f3(strtod(argv[2], NULL));		
            }
            else
            {
                puts("Argument not found");
            }
        }
        if(!strcmp(argv[i], "-test-integral"))
        {
            test_integral();
        }
        if(!strcmp(argv[i], "-test-root"))
        {
            test_root();
        }
        if(!strcmp(argv[i], "-solve"))
        {
            solve();
        }
        if(!strcmp(argv[i], "-show-absciss"))
        {
            show_absciss();
        }
        if(!strcmp(argv[i], "-show-count"))
        {
            show_count();
        }
    }
    return 0;
}

