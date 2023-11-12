#include <stdio.h>
#include <math.h>

#define Uo 4.807e-19
#define a 0.5e-9
#define m 9.1E-31
#define Hcut 1.054E-34

double k(double E)
{
    double u;
    u = sqrt((2 * m * E) / (Hcut * Hcut));
    return u;
}

double alpha(double E)
{
    double u;
    u = sqrt((2 * m * (Uo - E)) / (Hcut * Hcut));
    return u;
}

double function(double E)
{
    double u;
    u = (((k(E) * k(E)) - (alpha(E) * alpha(E))) / (2 * alpha(E) * k(E))) - (1 / tan(k(E) * a));
    return u;
}

int main()
{

    FILE *ptr;

    ptr = fopen("n.txt", "w");

    for (double i = 0; i <= 5e-19;)
    {
        fprintf(ptr, "%0.50lf %0.50lf\n", i, function(i));
        i+=1e-22;
    }

    double p, b, d, e;

    p = 2e-19;
    b = 5e-19;

    while (1)
    {

        d = (p + b) / 2;

        if (function(p) * function(d) < 0)
        {
            b = d;
        }

        else if (function(b) * function(d) < 0)
        {
            p = d;
        }

        e = (p + b) / 2;

        if (function(p) * function(e) < 0)
        {
            b = e;
        }

        else if (function(b) * function(e) < 0)
        {
            p = e;
        }

        if (fabs(d - e) < 1e-20)
        {
            break;
        }
    }
    printf("%e\n", e);
}