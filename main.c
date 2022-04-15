#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double max(double first_number, double second_number)
{
    if(first_number > second_number)
    {
        return first_number;
    }
    return second_number;
}

double min(double first_number, double second_number)
{
    if(first_number < second_number)
    {
        return first_number;
    }
    return second_number;
}


double max3(double first_number, double second_number, double third_number)
{
    return max(max(first_number, second_number), third_number);
}


double min3(double first_number, double second_number, double third_number)
{
    return min(min(first_number, second_number), third_number);
}


double mid3(double first_number, double second_number, double third_number)
{
    return min3(max(first_number, second_number), max(second_number, third_number), max(first_number, third_number));
}


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
    printf("%lf\n", max3(3, 2, 1));
    printf("%lf\n", max3(2, 3, 1));
    printf("%lf\n", max3(1, 2, 3));
    
    printf("%lf\n", min3(3, 2, 1));
    printf("%lf\n", min3(2, 3, 1));
    printf("%lf\n", min3(1, 2, 3));
    
    printf("%lf\n", mid3(3, 2, 1));
    printf("%lf\n", mid3(2, 3, 1));
    printf("%lf\n", mid3(1, 2, 3));
    
    double a, b, c;
    a = root(f1, f2, 0, 100, 0.1);
    b = root(f3, f2, 0, 100, 0.1);
    c = root(f1, f3, 0, 100, 0.1);
    
    if(min3(a, b, c) == a)
    {
        if(max3(a, b, c) == b)
        {
            // f2
        }
        else // max3(a, b, c) == c
        {
            //f1
        }
    }
    else if(min3(a, b, c) == b)
    {
        if(max3(a, b, c) == a)
        {
            // f2
        }
        else // max3(a, b, c) == c
        {
            //f3
        }
    }
    else // min3(a, b, c) == c
    {
        if(max3(a, b, c) == a)
        {
            // f1
        }
        else // max3(a, b, c) == b
        {
            //f3
        }
    }
    
    return 0;
}

