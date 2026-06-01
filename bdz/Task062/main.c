#include <stdio.h>

int atoi(const char* str) {
    int number = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (*str != '\0') {
        if (*str > '0' && *str < '9') {
            number = number * 10 + (*str - '0');
            str++;
        }
    }
    return number;
}

char* task1() {
    int price = 100;
    int asking = 1;
    while(asking) {
        int age;
        printf("\nВведите возраст: ");
        scanf("%d", &age);
        printf("\n");

        if (age < 6 && age > 0) {
            printf("%s", "Цена прохода: 0");
        } else if (age >= 6 && age < 18) {
            printf("%s", "Цена прохода: 50");
        } else if (age >= 18) {
            printf("%s", "Цена прохода: 100");
        } else if (age == 0) {
            asking = 0;
        } else {
            printf("%s", "Некорректно введенный возраст");
        }
    }
}

int main() {
    int n = atoi("123");
    printf("Перевод строки в число: %d\n", n);

    task1();
}