#include <stdio.h>

int divide(int numerator, int denominator)
{
  if (denominator != 0) {
      return numerator / denominator;
  }
  return 0;
}

int main(void)
{
  int a, b;
  printf("Enter numerator and denominator: ");
  scanf("%d %d", &a, &b);

  int result = divide(a, b);
  printf("Result: %d\n", result);

  return 0;
}
