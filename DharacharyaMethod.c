#include <stdio.h>
#include <math.h>

double dharacharya1(double a, double b, double c)
{
    double root1_a = (-b) / 2 * a;
    double root1_b = sqrt(b * b - 4 * a * c) / 2 * a;

    return (root1_a + root1_b);
}

double dharacharya2(double a, double b, double c)
{
    double root1_a = (-b) / 2 * a;
    double root1_b = sqrt(b * b - 4 * a * c) / 2 * a;

    return (root1_a - root1_b);
}

int main()
{
    double a = 1, b = -3000.001, c = -3;
    double roots1 = dharacharya1(a, b, c);
    double roots2 = dharacharya2(a, b, c);
    printf("%lf\n", roots1);
    printf("%lf\n", roots2);
}

float dharacharya1(float a, float b, float c)
{
    float root1_a = (-b) / 2 * a;
    float root1_b = sqrt(b * b - 4 * a * c) / 2 * a;

    return (root1_a + root1_b);
}

float dharacharya2(float a, float b, float c)
{
    float root1_a = (-b) / 2 * a;
    float root1_b = sqrt(b * b - 4 * a * c) / 2 * a;

    return (root1_a - root1_b);
}

int main()
{
    float a = 1, b = -3000.001, c = -3;
    float roots1 = dharacharya1(a, b, c);
    float roots2 = dharacharya2(a, b, c);
    printf("%f\n", roots1);
    printf("%f\n", roots2);
}