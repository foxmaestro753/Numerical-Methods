#include <stdio.h>

double lagrange_interpolation(double x[], double y[], int n, double target_x)
{
    double result = 0.0;
    for (int i = 0; i < n; i++)
    {
        double term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                term *= (target_x - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main()
{
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {1, 4, 9, 16, 25};
    int n = sizeof(x) / sizeof(x[0]);
    double target_x = 200;

    double estimated_y = lagrange_interpolation(x, y, n, target_x);
    printf("The estimated y-value at x = %.2f is %.2f\n", target_x, estimated_y);

    return 0;
}
