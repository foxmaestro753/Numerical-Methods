#include <stdio.h>
#include <math.h>

double fermi(float T)
{
    double K = 1.38066e-23;
    double a = 8.01088e-22;
    double b = a / (K * T);
    double c = 1 / (1 + exp(b));
    return c;
}

int main()
{

    FILE *ptr;

    ptr = fopen("fermi.txt", "w");

    for (float i = 0.5; i <= 5;)
    {
        fprintf(ptr, "%f %0.50lf\n", i, fermi(i));
        i = i + 0.001;
    }
}