#include <stdio.h>

double factorial(int n)
{
  if (n < 0) {
    return -1.0;
  }
  double res = 1;
  for (int i = 1; i < n + 1; i++) {
    res *= i;
  }
  return res;
}

int main(void)
{
  int n;
  scanf("%d", &n);
  double result = factorial(n);
  printf("%.0f\n", result);
  return 0;
}
