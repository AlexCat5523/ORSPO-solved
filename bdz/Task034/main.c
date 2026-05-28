#include <stdio.h>

double progression(int a1, int d, int n)
{
  double res = (double)(a1 + (n - 1) * d);
  return res;
}

int main(void)
{
  int a1, d, n;
  scanf("%d %d %d", &a1, &d, &n);
  printf("%.6f\n", progression(a1, d, n));
  return 0;
}
