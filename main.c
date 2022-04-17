#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rifunctions.h"
#include "minmax.h"
#include "functions.h"


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
    return 0;
}

