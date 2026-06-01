#include <stdio.h>

char *strcat(char *dest, const char *str) {    
    while (*dest != '\0') {
        dest++;
    }

    while (*str != '\0') {
        *dest = *str;
        dest++;
        str++;
    }
    *dest = '\0';
    return dest;
}


int main() {
    char dest[50] = "Hello, ";
    char str[] = "World";

    strcat(dest, str);

    printf("%s", dest);
}