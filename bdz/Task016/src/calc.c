#include "calc.h"
#include <stdio.h>

int sum_array(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {   // <--- тут была ошибка, что i начиналась с 1, т.е. первый элемент массива не учитывался
        sum += arr[i];
    }
    return sum;
}

int divide(int a, int b) {
    if (b == 0) {
        return 0;       // <--- добавляем проверку, что если b == 0, возвращаем 0.
    }
    return a / b;                   // <--- тут был знак умножения, хотя функция выполняет деление
}


