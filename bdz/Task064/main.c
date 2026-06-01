#include <stdio.h>

char* strcat(char *dest, const char *src) {
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest;
}


int main()
{
    char greeting[50] = "Hello, ";
    char name[] = "Alice";

    strcat(greeting, name);

    printf("%s\n", greeting);

    return 0;
}