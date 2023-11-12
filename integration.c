#include <math.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#define Nc 2.8e25

double function(double x)
{
    double u;
    u = (sqrt(x)) / ((exp(x - 4)) + 1);
    return u;
}

int main()
{

    double integrand = 0;
    double dI = 1e-3;
    double a, b;
    double i;

    while (1)
    {
        integrand += function(i) * dI;

        a = integrand;

        integrand += function(i + dI) * dI;

        b = integrand;

        if (b - a < 1e8)
        {
            break;
        }

        i += dI;
    }
    double answer = Nc * (2 / sqrt(3.14159)) * integrand;
    printf("%e", answer);
}