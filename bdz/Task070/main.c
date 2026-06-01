#include <stdio.h>

char *strstr(const char *string, const char *substr) {
    if (*string == '\0') {
        return (char*)string;
    }

    for (const char *word = string; *word != '\0'; word++) {
        const char *str_ptr = word;
        const char *substr_ptr = substr;

        while (*str_ptr != '\0' && *substr_ptr != '\0' && *str_ptr == *substr_ptr) {
            str_ptr++;
            substr_ptr++;
        }

        if (*substr_ptr == '\0') {
            return (char*)word;
        }
    }

    return 0;
}

int main() {
    const char *s1 = "Hello World";
    const char *s2 = "World";

    printf("Index: %ld", strstr(s1, s2) - s1);

}