#include <stdio.h>

void main() {

    char str[256];
    printf("Введите фразу: ");
    fgets(str, sizeof(str), stdin);
    printf("%s", str);
}