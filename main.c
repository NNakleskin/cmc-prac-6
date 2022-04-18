#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rifunctions.h"
#include "minmax.h"
#include "functions.h"
#include "handler.h"


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
    if(argv[1] == "-test-integral")
    {
        test_integral();
    }
    if(argv[1] == "-test-root")
    {
        test_integral();
    }
    return 0;
}

