#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rifunctions.h"
#include "minmax.h"
#include "functions.h"


void help()
{
    printf("-test-integral - do test with integral function\n");
    printf("-test-root - do test with root function\n");
    printf("-test-f1 <arg> - calculate function with user arg\n");
    printf("-test-f2 <arg> - calculate function with user arg\n");
    printf("-test-f3 <arg> - calculate function with user arg\n");
}

void test_integral()
{
    printf("integ f1 [1, 3] %lf\n", integral(f1, 1, 3, 0.1));
    printf("integ f2 [1, 3] %lf\n", integral(f2, 1, 3, 0.1));
    printf("integ f3 [1, 3] %lf\n", integral(f3, 1, 3, 0.1));
    printf("integ f1 [4, 15] %lf\n", integral(f1, 4, 15, 0.1));
    printf("integ f2 [3, 5] %lf\n", integral(f2, 3, 5, 0.1));
    printf("integ f3 [15, 43] %lf\n", integral(f3, 15, 43, 0.1));
}


void test_root()
{
    printf("root f1, f2 [2, 3] %lf\n", root(f2, f1, 2.0, 10.0, 0.0001));
    printf("root f2, f3 [2, 3] %lf\n", root(f2, f3, 0.0, 10.0, 0.0001));
    printf("root f1, f3 [2, 3] %lf\n", root(f1, f3, 0.0, 10.0, 0.0001));
}


void test_f1(double x)
{
    printf("%lf", f1(x));
}


void test_f2(double x)
{
    printf("%lf", f2(x));
}


void test_f3(double x)
{
    printf("%lf", f3(x));
}
