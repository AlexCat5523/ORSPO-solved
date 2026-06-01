#include <stdio.h>

int strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' || *str2 != '\0') {
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

int main() {
    const char* s1 = "Hello";
    const char* s2 = "Hello";

    printf("%d\n", strcmp(s1, s2));

}