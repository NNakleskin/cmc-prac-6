#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rifunctions.h"
#include "minmax.h"
#include "functions.h"
#include <stdio.h>
#include "counter.h"
#include "test_functions.h"


void help()
{
    printf("HELP\n\n");
    printf("-test-integral - do test with integral function\n");
    printf("-test-root - do test with root function\n");
    printf("-test-f1 <arg> - calculate function with user arg\n");
    printf("-test-f2 <arg> - calculate function with user arg\n");
    printf("-test-f3 <arg> - calculate function with user arg\n");
    printf("-solve - solve the problem\n");
    printf("-show_count - show count of iterations");
    printf("-show_absciss - show absciss of functions");
    printf("\n\n\n");
}

void test_integral()
{
    printf("TEST INTEGRAL\n\n");
    printf("integ f1 [1, 3] %lf\n", integral(f1, 1, 3, 0.1));
    printf("integ f2 [1, 3] %lf\n", integral(f2, 1, 3, 0.1));
    printf("integ f3 [1, 3] %lf\n", integral(f3, 1, 3, 0.1));
    printf("integ f1 [4, 15] %lf\n", integral(f1, 4, 15, 0.1));
    printf("integ f2 [3, 5] %lf\n", integral(f2, 3, 5, 0.1));
    printf("integ f3 [15, 43] %lf\n", integral(f3, 15, 43, 0.1));
    printf("Other funcrions\n");
    printf("2 * x * x: [1 , 2] Answer: 4,66667 Result: %lf\n", integral(f4, 1, 2, 0.001));
    printf("8 + 2x - x^2): [-2, 4] Answer: 36 Result: %lf\n", integral(f5, -2, 4, 0.001));
    printf("\n\n\n");
}


void test_root()
{
    printf("TEST ROOT\n\n");
    extern int count;
    printf("root f1, f2 [2, 3] %lf\n", root(f2, f1, 2.0, 10.0, 0.0001));
    printf("Count: %d\n", count);
    printf("root f2, f3 [2, 3] %lf\n", root(f2, f3, 0.0, 10.0, 0.0001));
    printf("Count: %d\n", count);
    printf("root f1, f3 [2, 3] %lf\n", root(f1, f3, 0.0, 10.0, 0.0001));
    printf("Count: %d\n", count);
    printf("Other funcrions\n");
    printf("2x + 1 && 6x Result: %lf\n", root(f6, f7, 0, 5, 0.00001));
    printf("Count: %d\n", count);
    printf("1/x && x Result: %lf\n", root(f3, f8, 0, 5, 0.001));
    printf("Count: %d\n", count);
    printf("\n\n\n");
}


void test_f1(double x)
{
    printf("TEST f1 with %lf\n\n", x);
    printf("%lf\n", f1(x));
    printf("\n\n\n");
}


void test_f2(double x)
{
    printf("TEST f2 with %lf\n\n", x);
    printf("%lf\n", f2(x));
    printf("\n\n\n");
}


void test_f3(double x)
{
    printf("TEST f3 with %lf\n\n", x);
    printf("%lf\n", f3(x));
    printf("\n\n\n");
}


void solve()
{
    printf("SOLVE\n\n");
    double root1 = root(f1, f2, 0, 5, 0.001);
    double root2 = root(f2, f3, 0, 5, 0.001);
    double root3 = root(f1, f3, 0, 5, 0.001);
    double S1 = integral(f1, root3, root1, 0.001);
    double S2 = integral(f2, root2, root1, 0.001);
    double S3 = integral(f3, root3, root2, 0.001);
    double S = S1 - S2 - S3;
    printf("%lf\n", S);
    printf("\n\n\n");
}


void show_absciss()
{
    printf("SHOW ABSCISS\n\n");
    printf("root f1, f2: %lf\n", root(f2, f1, 0.0, 5.0, 0.0001));
    printf("root f2, f3: %lf\n", root(f2, f3, 0.0, 5.0, 0.0001));
    printf("root f1, f3: %lf\n", root(f1, f3, 0.0, 5.0, 0.0001));
    printf("\n\n\n");
}


void show_count()
{
    printf("SHWO COUNT\n\n");
    printf("root f1, f2: %d\n", root_counter(f2, f1, 0.0, 5.0, 0.0001));
    printf("root f2, f3: %d\n", root_counter(f2, f3, 0.0, 5.0, 0.0001));
    printf("root f1, f3: %d\n", root_counter(f1, f3, 0.0, 5.0, 0.0001));
    printf("\n\n\n");
}