double root_counter(double (*f)(double), double(*g)(double), double a, double b, double eps)
{
    double x = (a + b) / 2;
    int count = 0;
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
    return count;
}