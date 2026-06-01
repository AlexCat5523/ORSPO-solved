#include <stdio.h>

int atoi(const char *string) {
    if (*string == '\0') {
        return 0;
    }

    int number = 0;
    int sign = 1;

    if (*string == '-') {
        sign = -1;
        string++;
    } else if (*string == '+') {
        string++;
    }

    while (*string != '\0') {
        int val = *string - 48;
        if (val < 0 || val > 9) {
            break;
        } else {
            number = number * 10 + val;
        }
        string++;
    }
    return number;
}

int main() {
    char *str = "123";
    int val = atoi(str); 
    printf("%d", val);
}