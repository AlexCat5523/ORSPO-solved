#include <stdio.h>

struct Empty {
    int c;
};

int main() {
    int x;
    int y = 10;
    printf("Size: %zu\n", sizeof(struct Empty));
    
    printf("Size: %zu\n", sizeof(x));
    printf("Y: %d", y);

    return 0;
}