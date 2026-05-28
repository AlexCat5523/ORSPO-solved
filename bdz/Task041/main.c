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

  if (n == 0) {
    printf("0 0");
  } else if (n == 1) {
    printf("%d %d", arr[0], arr[0]);
  } else {
    int maxi = -51325123;
    int mini = 51325123;
    for (int i = 0; i < n; i++) {
      int val = arr[i];

      if (val > maxi) {
        maxi = val;
      }
      if (val < mini) {
        mini = val;
      }
    }
    printf("%d %d", maxi, mini);
  }

  return 0;
}
