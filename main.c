#include "stdio.h"
#include "math.h"
#include "stdlib.h"

#define NOT_SUPPORTED_VAR -1


double f(double x, int var)
{
    if(var == 1)
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
    return NOT_SUPPORTED_VAR;
}

double root(double (*f)(double, int), double(*g)(double, int), double a, double b, double eps1, int var)
{
    double x = 0;
    while(fabs(a + b) > 2 * eps1)
    {
        x = (a + b) / 2;
        if(f(x, var) * f(a, var) < 0)
        {
            b = x;
        }
        if(f(x, var) * f(a, var) < 0)
        {
            a = x;
        }
    }
    return x;
}


double integral(double(*f), int a, int b, double eps2);


int main(void)
{
    double x;
    int a, b;
    
    printf("%lf", f(12.0, 4));
    return 0;
}

