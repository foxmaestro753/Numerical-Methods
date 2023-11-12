#include <stdio.h>
#include <math.h>

#define EG 1.76239e-19
#define ND 1e23
#define NC 2.3e25
#define NV 1e25
#define KB 1.380649e-23
#define E 8.010883e-22

double poten(double x, int T)
{
    double u;
    u = ((ND * NC) / (NC + 2 * x * exp(E / (KB * T)))) + (((NC * NV) / x) * exp(-EG / (KB * T))) - x;
    return u;
}

double potend(double x, int t)
{
    double g;
    double h = 1E12;
    g = (poten(x + h, t) - poten(x, t)) / h;
    return g;
}

int main()
{

    FILE *ptr;

    ptr = fopen("n.txt", "w");

    for (int i = 25; i <= 800; i++)
    {

        double a, b, c;

        a = 1e21;

        while (1)
        {

            b = a - (poten(a, i) / potend(a, i));

            a = b;

            c = a - (poten(a, i) / potend(a, i));

            a = c;

            if (fabs(b - c) < 1E12)
            {
                break;
            }
        }
        fprintf(ptr, "%d %e\n", i, c);
    }
}