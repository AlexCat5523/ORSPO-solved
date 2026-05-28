#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int sum = 0;

  if (argc != 1) {
    for (int i = 0; i < argc; i++) {
      sum += atoi(argv[i]);
    }
  } else {
    printf("No numbers provided\n");
  }

  printf("%d\n", sum);
  return 0;
}
