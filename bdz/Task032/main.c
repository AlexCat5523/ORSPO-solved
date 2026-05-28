#include <stdio.h>
#include <string.h>

int is_palindrome(const char *s)
{
  int ind = 0;
  int count = 0;
  while (s[ind] != '\0') {
    ind++;
    count++;
  }
  for (int i = 0; i < count; i++) {
    if (s[i] != s[count - i - 1]) {
      return 0;
    }
  }
  return 1;
}

int main(void)
{
  char s[101];
  scanf("%100s", s);
  if (is_palindrome(s))
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
