#include <stdio.h>

const char *get_time_of_day(int n)
{
  int hours = n / 3600;
  int minutes = n / 60;

  if (hours >= 0 && hours < 6) {
    return "Night";
  } else if (hours >= 6 && hours < 12) {
    return "Morning";
  } else if (hours >= 12 && hours < 18) {
    return "Day";
  } else if (hours >= 18 && hours < 24) {
    return "Evening";
  }
}

int main(void)
{
  int n;
  scanf("%d", &n);
  const char *tod = get_time_of_day(n);
  printf("%s\n", tod);
  return 0;
}
