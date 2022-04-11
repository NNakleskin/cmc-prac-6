#include "stdio.h"
#include "math.h"
#include "stdlib.h"


double f(double x, int var)
{
    if(var)
    {
        return 1 / exp(x) + 3;
    }
    if(var == 2)
    {
        return 2 * x - 2;
    }
    if(var == 3)
    {
        return 1 / x;
    }
    return 0;
}

double root(double(*f), double(*g), int a, int b, double eps1);


double integral(double(*f), int a, int b, double eps2);


int main(void)
{
    double x;
    
    return 0;
}

