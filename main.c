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
    if(!strcmp(argv[1], "-help"))
    {
        help();
    }
    if(!strcmp(argv[1], "-test-f1"))
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
    if(!strcmp(argv[1], "-test-f2"))
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
    if(!strcmp(argv[1], "-test-f3"))
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
    if(!strcmp(argv[1], "-test-integral"))
    {
        test_integral();
    }
    if(!strcmp(argv[1], "-test-root"))
    {
        test_root();
    }
    if(!strcmp(argv[1], "-solve"))
    {
        solve();
    }
    return 0;
}

