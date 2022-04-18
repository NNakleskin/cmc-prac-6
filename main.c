#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "handler.h"
#include <string.h>


/*
double f1(double x)
{
    return 1 / exp(x) + 3;
}


double f2(double x)
{
    return 2 * x - 2;
}


double f3(double x)
{
    return 1 / x;
}
*/

int main(int argc, char **argv)
{
    short status = 0;
    if(!strcmp(argv[1], "-help"))
    {
        status = 1;
        help();
    }
    if(!strcmp(argv[1], "-test-f1"))
    {
        status = 1;
        if(argc == 3)
        {
            test_f1(strtod(argv[2], NULL));		
        }
        else
        {
            puts("Argument not found");
        }
    }
    if(!strcmp(argv[1], "-test-f2"))
    {
        status = 1;
        if(argc == 3)
        {
            test_f2(strtod(argv[2], NULL));		
        }
        else
        {
            puts("Argument not found");
        }
    }
    if(!strcmp(argv[1], "-test-f3"))
    {
        status = 1;
        if(argc == 3)
        {
            test_f3(strtod(argv[2], NULL));		
        }
        else
        {
            puts("Argument not found");
        }
    }
    if(!strcmp(argv[1], "-test-integral"))
    {
        status = 1;
        test_integral();
    }
    if(!strcmp(argv[1], "-test-root"))
    {
        status = 1;
        test_root();
    }
    if(!strcmp(argv[1], "-solve"))
    {
        status = 1;
        solve();
    }
    if(!status)
    {
        help();
    }
    return 0;
}

