#include <stdio.h>

#define CAPACITY 50000 // Size of the Hash Table

unsigned long hash_function(char* str) {
    unsigned long i = 0;
    for (int j=0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}

int main() {
    char str[CAPACITY - 1];
    char c;

    FILE *fp = fopen("data.txt", "r");

    int i = 0;
    if (fp) {
        while ((c = getc(fp)) != EOF) {
            str[i] = c;
            i++;
        }
    }
    fclose(fp);

    unsigned long hash_before = hash_function(str);
    
    fp = fopen("data.txt", "w");

    char string_to_write[5] = "MPSU";
    if (fp) {
        for (int i = 0; i < 4; i++) {
            putc(string_to_write[i], fp);
        }
        fclose(fp);
    }

    fp = fopen("data.txt", "r");
    i = 0;
    char another_str[CAPACITY - 1];
    if (fp) {
        while ((c = getc(fp)) != EOF) {
            another_str[i] = c;
            i++;
        }
    }
    fclose(fp);

    unsigned long hash_after = hash_function(another_str);

    printf("Hash before change: %ld\n Hash after change: %ld\n", hash_before, hash_after);
}