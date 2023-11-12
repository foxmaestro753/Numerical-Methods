#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double optimum(double h)
{
    double g;
    g = (sin(M_PI_4 + h) - sin(M_PI_4)) / h;
    return g;
}

int main()
{
    double t = cos(M_PI_4);

    FILE *ptr;

    ptr = fopen("sinx.txt", "w");

    for (double i = 1; i >= 1e-20; i = i / 10)
    {
        fprintf(ptr, "%0.23lf %0.50lf %0.50lf\n", i, optimum(i), t - optimum(i));
    }
}