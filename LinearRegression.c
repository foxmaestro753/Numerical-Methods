#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *fp;
    fp = fopen("data_linear.txt", "r");
    double matrix[100][2];

    for (int i = 0; i < 2631; i++)
    {
        fscanf(fp, "%lf", &matrix[i][0]);
        fscanf(fp, "%lf", &matrix[i][1]);
    }

    double x[] = {1.2, 2.3, 3.8, 4.9, 5.9};
    double y[] = {1.245, 4.90, 9.67, 16.67, 25.89};
    int n = sizeof(x) / sizeof(x[0]);

    int n = 100;

    double sumx = 0.0;
    double sumy = 0.0;
    double sumxy = 0.0;
    double sumx2 = 0.0;

    for (int i = 0; i < n; i++)
    {
        sumx += matrix[i][0];
        sumy += matrix[i][1];
        sumxy += matrix[i][0] * matrix[i][1];
        sumx2 += matrix[i][0] * matrix[i][0];
    }

    double m = ((n * sumxy) - (sumx * sumy)) / ((n * sumx2) - (sumx * sumx));
    double c = (sumy - m * sumx) / n;

    FILE *fp1 = fopen("linearreg.txt", "w");

    for (double i = 1; i <= 100; i += 0.0001)
    {
        fprintf(fp1, "%0.18lf %0.18lf\n", i, (m * i + c));
    }
    printf("%0.50lf %0.50lf", m, c);
    fclose(fp);

    return 0;
}