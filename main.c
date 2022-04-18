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

int main(char* key)
{
    if(key == "-test-integral")
    {
        test_integral();
    }
    return 0;
}

