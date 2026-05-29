#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gen_array(double** arr, int n) {
    for (int i = 0; i < n; i++) {   // строки
        for (int j = 0; j < n; j++) {   // столбцы
            double denom = rand() % 10 + 1;
            double val = (rand() % 100) / denom;
            arr[i][j] = val;
        }
    }
}

void print_array(double** arr, int n) {
    for (int i = 0; i < n; i++) {   // строки
        for (int j = 0; j < n; j++) {
            printf("%lf ", arr[i][j]);
        }
        printf("\n");
    }
}

double max_array(double** arr, int n) {
    double maxi = -1;
    for (int i = 0; i < n; i++) {   // строки
        for (int j = 0; j < n; j++) {   // столбцы
            if (arr[i][j] > maxi) {
                maxi = arr[i][j];
            }
        }
    }
    return maxi;
}

int main() {
    srand(time(NULL));

    int n = 6;
    double** lis = (double**)malloc(n * sizeof(double*));       // выделяем память под саму матрицу (двумерный массив)
    
    if (lis == NULL) {
        printf("lis malloc failed");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        lis[i] = (double*)malloc(n * sizeof(double));  // выделяем память под каждую строку матрицы
        if (lis[i] == NULL) {
            printf("row %d malloc failed", i);
            return 1;
        }
    }

    gen_array(lis, n);
    print_array(lis, n);
    printf("Max element: %lf\n", max_array(lis, n));

    for (int i = 0; i < n; i++) {
        free(lis[i]);
    }
    free(lis);
    return 0;
}