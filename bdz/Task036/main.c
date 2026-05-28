#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double *x1, double *x2)
{
  double discr = sqrt(b * b - 4 * a * c);

  *x1 = ((-b + discr) / (2 * a));
  *x2 = ((-b - discr) / (2 * a));
  printf("Roots: %lf %lf", *x1, *x2);
}

int main(void)
{
  double a, b, c;
  double x1, x2;
  scanf("%lf %lf %lf", &a, &b, &c);

  int roots = solve_quadratic(a, b, c, &x1, &x2);

  if (roots == 0)
    printf("No real roots\n");

  return 0;
}
