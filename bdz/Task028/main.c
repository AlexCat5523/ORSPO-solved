#include <stdio.h>

int middle_of_three(int a, int b, int c)
{
  if ((a >= b && a <= c) || (a >= c && a <= b)) {
    return a;
  }

  if ((b >= a && b <= c) || (b >= c && b <= a)) {
    return b;
  }

  return c;
}

int main(void)
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d\n", middle_of_three(a, b, c));
  return 0;
}
