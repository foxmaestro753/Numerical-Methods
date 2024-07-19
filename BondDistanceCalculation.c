#include <stdio.h>
#include <math.h>

#define EP 8.854187817e-12
#define PI 3.14159
#define Q 1.602e-19
#define V 1.74637253e-16
#define R 0.33e-10

double poten(double x)
{
    double u;
    u = ((Q * Q) / (4 * PI * EP * x)) - (V * exp((-x) / R));
    return u;
}

double potend(double h)
{
    double g;
    g = (poten(1e-10 + h) - poten(1e-10)) / h;
    return g;
}

int main()
{

    double t = 2.306e-28;

    FILE *ptr;

    ptr = fopen("bondcheck.txt", "w");

    for (double i = 1; i >= 1e-30; i = i / 10)
    {
        fprintf(ptr, "%0.33lf %0.50lf %0.50lf\n", i, potend(i), t - potend(i));
    }
}