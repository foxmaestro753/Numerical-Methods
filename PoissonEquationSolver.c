#include <stdio.h>
#include <math.h>
#define h 2.020202e-9
#define Nd 1e23
#define Nc 3e25
#define Nv 3e25
#define Eg 1.76239e-19
#define Q 1.609e-19
#define E 1.053626e-10
#define KbT 4.1657e-21

void WriteToFile(int N, double X[], double Ec[])
{
    FILE *fptr;
    fptr = fopen("EcX.txt", "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(fptr, "%e %0.15e \n", X[i], Ec[i]);
    }
}

void matrixmult(int n, double array1[][n], double array2[][n], double array3[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array3[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                array3[i][j] += (array1[i][k] * array2[k][j]);
            }
        }
    }
}

void matrixmult1(int n, double array1[][n], double array2[], double array3[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array3[i] = 0;
            for (int k = 0; k < n; k++)
            {
                array3[i] += (array1[i][k] * array2[k]);
            }
        }
    }
}

double n(double x)
{
    double u;
    u = Nc * exp(-x / KbT);
    return u;
}

double p(double x)
{
    double u;
    u = Nv * exp(x - Eg / KbT);
    return u;
}

double function(int i, double array[], double x)
{
    double u;
    u = ((array[i + 1] - 2 * array[i] + array[i - 1]) / h * h) + ((Q * (Nd + p(x) - n(x))) / E);
    return u;
}

int main()
{
    int N = 100;
    double matrix[N][N];
    double coefficient[N];
    double V[N];
    double transform[N][N];
    double product1[N][N];
    double product2[N];
    double e;
    double X[N];
    double Ec[N];

    for (int p = 0; p < N; p++)
    {
        V[p] = -0.14;
    }

    for (int p = 0; p < N; p++)
    {
        if (p == 0 || p == N - 1)
        {
            coefficient[p] = 0;
            continue;
        }
        coefficient[p] = -function(p, V, V[p] * -Q);
    }

    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j == i - 1)
            {
                matrix[i][j] = ((1) / pow(h, 2)) + ((Q * ((((p(V[j] * -Q)) * -Q) / KbT) + ((-Q * (n(V[j] * -Q))) / KbT))) / E);
            }
            else if (j == i)
            {
                matrix[i][j] = ((-2) / pow(h, 2)) + ((Q * ((((p(V[j] * -Q)) * -Q) / KbT) + ((-Q * (n(V[j] * -Q))) / KbT))) / E);
            }
            else if (j == i + 1)
            {
                matrix[i][j] = ((1) / pow(h, 2)) + ((Q * ((((p(V[j] * -Q)) * -Q) / KbT) + ((-Q * (n(V[j] * -Q))) / KbT))) / E);
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }

    matrix[0][0] = 1;

    for (int x = 1; x < N; x++)
    {
        matrix[0][x] = 0;
    }

    matrix[N - 1][N - 1] = 1;

    for (int x = 0; x < N - 1; x++)
    {
        matrix[N - 1][x] = 0;
    }

    while (1)
    {

        for (int i = 0; i < N; i++)
        {
            if (matrix[i][i] != 1)
            {
                e = matrix[i][i];
                for (int p = 0; p < N; p++)
                {
                    matrix[i][p] = matrix[i][p] / e;
                }

                coefficient[i] = coefficient[i] / e;
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (i == j)
                    {
                        transform[i][j] = 1;
                    }
                    else
                    {
                        transform[i][j] = 0;
                    }
                }
            }

            for (int j = 0; j < N; j++)
            {
                if (j != i)
                {
                    transform[j][i] = -matrix[j][i];
                }
            }

            matrixmult(N, transform, matrix, product1);
            matrixmult1(N, transform, coefficient, product2);

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    matrix[i][j] = product1[i][j];
                }
            }

            for (int i = 0; i < N; i++)
            {
                coefficient[i] = product2[i];
            }
        }

        for (int p = 0; p < N; p++)
        {
            V[p] = V[p] + coefficient[p];
        }

        double max = coefficient[0];

        for (int p = 1; p < N; p++)
        {
            if (coefficient[p] > max)
            {
                max = coefficient[p];
            }
        }

        if (max < 1e-10)
        {
            break;
        }

        for (int p = 0; p < N; p++)
        {
            if (p == 0 || p == N - 1)
            {
                coefficient[p] = 0;
                continue;
            }
            coefficient[p] = -function(p, V, V[p] * -Q);
        }

        for (int i = 1; i < N - 1; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (j == i - 1)
                {
                    matrix[i][j] = ((1) / pow(h, 2)) + ((Q * ((((p(V[j] * -Q)) * -Q) / KbT) + ((-Q * (n(V[j] * -Q))) / KbT))) / E);
                }
                else if (j == i)
                {
                    matrix[i][j] = ((-2) / pow(h, 2)) + ((Q * ((((p(V[j] * -Q)) * -Q) / KbT) + ((-Q * (n(V[j] * -Q))) / KbT))) / E);
                }
                else if (j == i + 1)
                {
                    matrix[i][j] = ((1) / pow(h, 2)) + ((Q * ((((p(V[j] * -Q)) * -Q) / KbT) + ((-Q * (n(V[j] * -Q))) / KbT))) / E);
                }
                else
                {
                    matrix[i][j] = 0;
                }
            }
        }

        matrix[0][0] = 1;

        for (int x = 1; x < N; x++)
        {
            matrix[0][x] = 0;
        }

        matrix[N - 1][N - 1] = 1;

        for (int x = 0; x < N - 1; x++)
        {
            matrix[N - 1][x] = 0;
        }
    }

    for (int p = 0; p < N; p++)
    {
        Ec[p] = -V[p];
    }

    double s = 0;

    for (int p = 0; p < N; p++)
    {
        X[p] = s;
        s += h;
    }

    WriteToFile(N, X, Ec);
}