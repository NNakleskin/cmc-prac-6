#include "stdio.h"
#include "math.h"
#include "stdlib.h"

#define NOT_SUPPORTED_VAR -1


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

double root(double (*f)(double), double(*g)(double), double a, double b, double eps1)
{
    double x = (a + b) / 2;
    while(fabs(b - a) > 2 * eps1)
    {
        if((f(x) - g(x)) * (f(a) - g(a)) < 0)
        {
            b = x;
        }
        else if((f(x) - g(x)) * (f(b) - g(b)) < 0)
        {
            a = x;
        }
        x = (a + b) / 2;
    }
    return x;
}


double integral(double(*f), int a, int b, double eps2);


int main(void)
{
    double x;
    int a, b;

    printf("%lf", root(f2, f1, 2.0, 3.0, 0.0001));
    return 0;
}

