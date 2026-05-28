#include <stdio.h>

double my_function(int x)
{
  double res = (double)(x * x + 5 * x + 6) / (1 + x + x * x);
  return res;
}

int main(void)
{
  int x;
  scanf("%d", &x);
  printf("%.6f\n", my_function(x));
  return 0;
}
