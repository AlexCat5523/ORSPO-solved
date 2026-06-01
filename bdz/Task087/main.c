#include <stdio.h>


#define print_value(x) _Generic((x), \
    int : print_int, \
    long: print_long, \
    float: print_float, \
    double: print_double, \
    char*: print_string, \
    void*: print_ptr, \
    default: print_error \
)(x)


#define max(x, y) _Generic((x), \
    int: max_int, \
    float: max_float, \
    double: max_double, \
    unsigned int: max_u_int, \
    short: max_short, \
    long: max_long, \
    long long: max_long_long, \
    unsigned long long: max_u_long_long, \
    default: max_default \
)(x)

int max_int(int x, int y) {
    return (x > y ? x : y);
}
float max_float(float x, float y) {
    return (x > y ? x : y);
}
double max_double(double x, double y) {
    return (x > y ? x : y);
}
unsigned int max_u_int(unsigned int x, unsigned int y) {
    return (x > y ? x : y);
}
short max_short(short x, short y) {
    return (x > y ? x : y);
}
long max_long(long x, long y) {
    return (x > y ? x : y);
}
long long max_long_long(long long x, long long y) {
    return (x > y ? x : y);
}
unsigned long long max_u_long_long(unsigned long long x, unsigned long long y) {
    return (x > y ? x : y);
}
void max_default(int x, int y) {
    printf("Unsupported type");
}


void print_int(int x) {
    printf("Int number: %d", x);
}
void print_long(long x) {
    printf("Long number: %ld", x);
}
void print_float(float x) {
    printf("Float: %f", x);
}
void print_double(double x) {
    printf("Double: %lf", x);
}
void print_string(char* x) {
    printf("String: %s", x);
}
void print_ptr(void* x) {
    printf("Number: %p", x);
}
void print_error(int x) {
    printf("unsupported type");
}

int main() {
    int number = 10;
    print_value(number);
}