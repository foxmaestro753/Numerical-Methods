#include <math.h>
#include <stdio.h>
#define Na 1e26
#define Nc 3e25
#define Nv 1e25
#define Eg 1.76239e-19
#define KbT 4.1657e-21
#define Q 1.60218e-19
#define pi 3.14159265359

double fermi(double y, double x)
{
    double u;
    u = (sqrt(y)) / ((exp(y - x)) + 1);
    return u;
}

double fermiintg(double x)
{
    double integrand = 0;
    double dI = 1e-4;

    for (double i = 0; i < 1e2;)
    {
        integrand += fermi(i, x) * dI;
        i += dI;
    }
    return integrand;
}

double function(double x)
{
    double u;
    u = -Na + (Nv * (2 / sqrt(pi)) * fermiintg((x - Eg )/ (KbT))) - (Nc * (2 / sqrt(pi)) * fermiintg((-x) / (KbT)));
    return u;
}

// INSTRUCTION:
// Upload your code on the Google Classroom by 5:30 pm
// Name Your File as: <RollNo>_Hackathon2.c.
// All the characters in the roll no should be small.
// Late submissions, incorrect filenames will not be considered for grading
// Ensure that the result is in eV
// Ensure that the Residual is in 1/m^3

// DO NOT MODIFY THIS FUNCTION
void PrintTheResult(double x, double Residual)
{
    printf("The Result is: %e in eV\n", x);
    printf("Residual: %e in 1/m3\n", Residual);
}

int main()
{

    double Result, Residual;

    // Your solution to the problem

    double a, b, d, e;

    a = -5*Eg;
    b = 5*Eg;

    while (1)
    {

        d = (a + b) / 2;

        if (function(a) * function(d) < 0)
        {
            b = d;
        }

        if (function(b) * function(d) < 0)
        {
            a = d;
        }

        e = (a + b) / 2;

        if (function(a) * function(e) < 0)
        {
            b = e;
        }

        if (function(b) * function(e) < 0)
        {
            a = e;
        }

        if (fabs(d - e) < 4.80653e-22)
        {
            break;
        }
    }

    // Assign the the values of Ec-Ef to the Result and the residual value to the Residual variable

    Result = e / Q;
    Residual = function(e);

    PrintTheResult(Result, Residual);

    return (0);
}