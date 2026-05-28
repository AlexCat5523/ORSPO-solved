#include <stdio.h>

void fizzbuzz(int n)
{
  for (int i = 0; i < n; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      printf("%d FizzBuzz\n", i);
    } else if (i % 5 == 0) {
      printf("%d Buzz\n", i);
    } else if (i % 3 == 0) {
      printf("%d Fizz\n", i);
    } else {
      printf("%d\n", i);
    }
  }
}

int main(void)
{
  int n;
  scanf("%d", &n);
  fizzbuzz(n);
  return 0;
}
