#include <stdio.h>

int array_sum(int arr[], int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      sum += arr[i];
    }
  }
  return sum;
}

int main(void)
{
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);
    arr[i] = val;
  }

  printf("Array sum: %d\n", array_sum(arr, n));

  return 0;
}
