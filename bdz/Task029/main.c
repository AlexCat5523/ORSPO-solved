#include <stdio.h>

int min_of_three(int a, int b, int c)
{
  if ((a <= b && b <= c) || (a <= c && c <= b)) {
    return a;
  }
  if ((b <= a && a <= c) || (b <= c && c <= a)) {
    return b;
  }
  return c;
}

int main(void)
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d\n", min_of_three(a, b, c));
  return 0;
}
