#include <stdio.h>
#include <math.h>

double rieman_integral(double (*f)(double), double x, double delt)
//Calculation of one term of the Riemann integral sum
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
        result += rieman_integral(f, x, delt);
        x += delt;
    }
    return result;
}