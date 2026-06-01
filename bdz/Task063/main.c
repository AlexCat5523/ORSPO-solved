#include <stdio.h>


int strcmp(const char *str1, const char *str2) {
    while(*str1 != '\0' || *str2 != '\0') {
        if (*str1 != *str2) {
            if (*str1 < *str2) {
                return -1;
            } else {
                return 1;
            }
        }
        str1++;
        str2++;
    } 
    return 0;
}

int main()
{
    char str1[] = "hello";
    char str2[] = "hello";

    int result = strcmp(str1, str2);

    if (result == 0)
        printf("Strings are equal\n");
    else if (result < 0)
        printf("str1 is less than str2\n");
    else
        printf("str1 is greater than str2\n");

    return 0;
}