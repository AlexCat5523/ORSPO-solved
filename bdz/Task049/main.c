#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gen_array(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        double denom = rang() % 10 + 1;
        double r = rand() % 1000;
        arr[i] = r / denom;
    }
}

void print_array(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Index %d: %lf\n", i, arr[i]);
    }
}

double max_array(double* arr, int n) {
    double maxi = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    return maxi;
}

void main() {
    srand(time(NULL));
    int n = 10;
    double* lis = (double*)malloc(n * sizeof(double));

    gen_array(lis, n);

    print_array(lis, n);

    printf("Максимальное значение: %lf\n", max_array(lis, n));
}