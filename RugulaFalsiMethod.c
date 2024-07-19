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

double potend(double x)
{
    double g;
    double h = 1E-13;
    g = (poten(x + h) - poten(x)) / h;
    return g;
}

int main()
{

    FILE *ptr;

    ptr = fopen("bond1.txt", "w");

    for (double i = 0.5e-12; i <= 1e-10;)
    {
        fprintf(ptr, "%0.18lf %0.50lf\n", i, poten(i));
        i = i + 1e-14;
    }

    ptr = fopen("bond2.txt", "w");

    for (double i = 0.5e-12; i <= 1e-10;)
    {
        fprintf(ptr, "%0.18lf %0.50lf\n", i, potend(i));
        i = i + 1e-14;
    }

    double a, b, d, e;

    a = 6e-12;
    b = 2e-11;

    while (1)
    {

        d = (a * potend(b) - b * potend(a)) / (potend(b) - potend(a));

        if (potend(a) * potend(d) < 0)
        {
            b = d;
        }

        if (potend(b) * potend(d) < 0)
        {
            a = d;
        }

        e = (a * potend(b) - b * potend(a)) / (potend(b) - potend(a));

        if (potend(a) * potend(e) < 0)
        {
            b = e;
        }

        if (potend(b) * potend(e) < 0)
        {
            a = e;
        }

        if (fabs(d-e) < 1E-13)
        {
            break;
        }
    }
    printf("%e", e);
}