#include <stdio.h>
#include <math.h>

#define Kb 1.3806452e-23
#define Ni 1.05e16
#define Nd 1e24

double poisson(double x, double T){
    double u;
    u = Nd + Ni*exp(-x/(Kb*T)) - Ni*exp(x/(Kb*T));
    return u;
}

int main()
{

    FILE *ptr;

    double T=300;

    ptr = fopen("n.txt", "w");

    for (double i = 1e-20; i <= 8e-20;)
    {
        fprintf(ptr, "%0.50lf %0.50lf\n", i, poisson(i,T));
        i+=1e-22;
    }

    double p, b, d, e;

    p = 0;
    b = 1e-19;

    while (1)
    {

        d = (p + b) / 2;

        if (poisson(p,T) * poisson(d,T) < 0)
        {
            b = d;
        }

        else if (poisson(b,T) * poisson(d,T) < 0)
        {
            p = d;
        }

        e = (p + b) / 2;

        if (poisson(p,T) * poisson(e,T) < 0)
        {
            b = e;
        }

        else if (poisson(b,T) * poisson(e,T) < 0)
        {
            p = e;
        }

        if (fabs(d - e) < 1e-24)
        {
            break;
        }
    }
    printf("%e\n", e);
}