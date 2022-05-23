#include <math.h>


double root(double (*f)(double), double(*g)(double), double a, double b, double eps)
{
    extern int count;
    double x = (a + b) / 2;
    count = 0;
    while(fabs(b - a) > 2 * eps)
    {
        count++;
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


double rieman_integral(double (*f)(double), double x, double delt)
//Calculation of one term of the Riemann integral sum
{
    return f((x + delt / 2)) * delt;
}


double make_integral(double(*f)(double), double a, double b, double n)
{
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

double integral(double(*f)(double), double a, double b, double eps)
{
    int n = 1;
    while(fabs(make_integral(f, a, b, n) - make_integral(f, a, b, 2 * n)) >= eps)
    {
        n++;
    }
    return make_integral(f, a, b, 2 * n);
}
