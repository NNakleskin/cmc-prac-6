#include "stdio.h"


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
