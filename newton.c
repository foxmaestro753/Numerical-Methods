#include <stdio.h>
#include <math.h>

#define W 2.662e-6
#define ME 5.974e24
#define MM 7.348e22
#define G 6.67430e-11
#define R 3.844e8

double poten(double x)
{
    double u;
    u = (G*ME)/(x*x) - (G*MM)/((R-x)*(R-x)) - W*W*x;
    return u;
}

double potend(double x)
{
    double g;
    double h = 1E6;
    g = (poten(x + h) - poten(x)) / h;
    return g;
}

int main()
{
    double a, b, c;

    a = 1e10;

    while (1)
    {

        b = a - (poten(a)/potend(a));

        c = b - (poten(b)/potend(b));

        a = c;

        if (b - c < 1E4)
        {
            break;
        }
    }
    printf("%e", c);
}