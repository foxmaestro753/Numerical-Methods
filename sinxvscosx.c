#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double optimum(double x)
{
    double g;
    g = (sin(x + 0.0000001) - sin(x)) / 0.0000001;
    return g;
}

int main()
{

    FILE *ptr;

    ptr = fopen("sinxd.txt", "w");

    for (double i = 1e-5; i <= 2 * M_PI; 1)
    {
        fprintf(ptr, "%0.23lf  %0.50lf\n", i, optimum(i));
        i = i + 0.001;
    }

    ptr = fopen("cosx.txt", "w");

    for (double i = 1e-5; i <= 2 * M_PI; 1)
    {
        fprintf(ptr, "%0.18lf %0.50lf\n", i, cos(i));
        i = i + 0.001;
    }
}