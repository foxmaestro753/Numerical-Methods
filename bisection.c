#include <stdio.h>
#include <math.h>

double potend(double x)
{
     double u;
     u = pow(x, 2) - 3;
     return u;
}

int main()
{

     double a, b, d, e;

     a = 0.0001;
     b = 100;

     while (1)
     {

          d = (a + b) / 2;

          if (potend(a) * potend(d) < 0)
          {
               b = d;
          }

          if (potend(b) * potend(d) < 0)
          {
               a = d;
          }

          e = (a + b) / 2;

          if (potend(a) * potend(e) < 0)
          {
               b = e;
          }

          if (potend(b) * potend(e) < 0)
          {
               a = e;
          }

          if (fabs(d-e) < 0.000000000000001)
          {
               break;
          }
     }
     printf("%0.100lf", e);
}
