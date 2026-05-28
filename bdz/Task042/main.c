#include <stdio.h>

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

  int prefix_arr[n];
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < i + 1; j++) {
      sum += arr[j];
    }
    prefix_arr[i] = sum;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", prefix_arr[i]);
  }
  return 0;
}
