#include "stdio.h"
#include "math.h"
#include "stdlib.h"


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


double square_int(double (*f)(double), double x, double delt)
{
    return f((x + delt / 2)) * delt;
}


double root(double (*f)(double), double(*g)(double), double a, double b, double eps)
{
    double x = (a + b) / 2;
    while(fabs(b - a) > 2 * eps)
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


double integral(double(*f)(double), double a, double b, double eps)
{
    double n = ((b - a) * (b - a)) / (eps * 2);
    double delt = (b - a) / n;
    double x = a;
    double result = 0;
    for(double i = 0; i < n; i++)
    {
        result += square_int(f, x, delt);
        x += delt;
    }
    return result;
}


int main(void)
{
    printf("integ f1 [1, 3] %lf\n", integral(f1, 1, 3, 0.1));
    printf("integ f2 [1, 3] %lf\n", integral(f2, 1, 3, 0.1));
    printf("integ f3 [1, 3] %lf\n", integral(f3, 1, 3, 0.1));
    printf("root f1, f2 [2, 3] %lf\n", root(f2, f1, 2.0, 10.0, 0.0001));
    printf("root f2, f3 [2, 3] %lf\n", root(f2, f3, 0.0, 10.0, 0.0001));
    printf("root f1, f3 [2, 3] %lf\n", root(f1, f3, 0.0, 10.0, 0.0001));
    printf("integ f1 [1, 3] %lf\n", integral(f1, 4, 15, 0.1));
    printf("integ f2 [1, 3] %lf\n", integral(f2, 3, 5, 0.1));
    printf("integ f3 [1, 3] %lf\n", integral(f3, 15, 43, 0.1));
    
    return 0;
}

