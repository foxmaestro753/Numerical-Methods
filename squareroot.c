#include <stdio.h>
#include <math.h>

double squareroot(double x, double a){
    double u;
    u = (x+(a/x))/2 - x ;
    return u;
}

int main()
{
    double number = 10;
    double p, b, d, e;

    p = 0;
    b = 1e100;

    while (1)
    {

        d = (p + b) / 2;

        if (squareroot(p,number) * squareroot(d,number) < 0)
        {
            b = d;
        }

        else if (squareroot(b,number) * squareroot(d,number) < 0)
        {
            p = d;
        }

        e = (p + b) / 2;

        if (squareroot(p,number) * squareroot(e,number) < 0)
        {
            b = e;
        }

        else if (squareroot(b,number) * squareroot(e,number) < 0)
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