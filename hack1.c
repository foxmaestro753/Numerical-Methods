#include <stdio.h>
#include <math.h>

#define Q 1.602e-19
#define E 1.053626e-10
#define Nd 1e20
#define EB 7.209795e-20
#define m 9.1E-31
#define Hcut 1.054e-34
#define W 2.43447e-6

double energy(double x)
{
    double u;
    if (x >= W || x < 0)
    {
        return 0;
    }
    else
    {
        u = (-Q * ((Q * Nd) / E) * ((W * x) - ((x * x) / 2))) +  EB;
        return (u);
    }
}

double t(double J, double X)
{
    double u;
    u = sqrt(2 * m * (energy(X) - J));
    return u;
}

int main()
{
    double dX = 1e-10;
    double dE = 1e-24;
    double integrand;
    double result = 0;

    for (double i = 0; i < 7.209795e-20 ;)
    {
        integrand = 0;

        for (double j = 0; j < W;)
        {
            if (energy(j) > i)
            {
                integrand += t(i,j)*dX;
            }
            else if (energy(j) < i)
            {
                break;
            }
            j += dX;
        }
        result += exp((-2/Hcut)*integrand)*dE;
        i += dE;
    }
    printf("%e",result);
}