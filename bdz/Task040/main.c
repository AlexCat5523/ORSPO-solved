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

  for (int i = 0; i < n; i++) {
    int count = -1;
    for (int j = 0; j < n; j++) {
      if (arr[i] == arr[j]) {
        count++;
      }
      if (count > 0) {
        printf("Duplicate: %d\n", arr[i]);
        return 1;
      }
    }
  }
  printf("No duplicates\n");

  return 0;
}
