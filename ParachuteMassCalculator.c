#include <stdio.h>
#include <math.h>

#define C 15
#define g 9.8

double masssolver(double x){
    double u;
    u = ((g*x)/C)*(1- exp((-C*9/x))) - 35 ;
    return u;
}

int main()
{
    double p, b, d, e;

    p = 0;
    b = 100;

    while (1)
    {

        d = (p + b) / 2;

        if (masssolver(p) * masssolver(d) < 0)
        {
            b = d;
        }

        if (masssolver(b) * masssolver(d) < 0)
        {
            p = d;
        }

        e = (p + b) / 2;

        if (masssolver(p) * masssolver(e) < 0)
        {
            b = e;
        }

        if (masssolver(b) * masssolver(e) < 0)
        {
            p = e;
        }

        if (fabs(d - e) < 1e-3)
        {
            break;
        }
    }
    printf("%e\n", e);
}