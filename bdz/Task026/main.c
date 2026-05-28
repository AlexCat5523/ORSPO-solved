#include <stdio.h>

void seconds_to_time(int n)
{
  int hours = n / (3600);
  int minutes = n / 60;
  printf("Hours: %d; Minutes: %d", hours, minutes);
}

int main(void)
{
  int n;
  scanf("%d", &n);
  seconds_to_time(n);
  return 0;
}
