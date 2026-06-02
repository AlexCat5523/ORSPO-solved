#include <stdio.h>


#define PRINT_VALUE(x) _Generic((x), \
    int : print_int, \
    long: print_long, \
    float: print_float, \
    double: print_double, \
    char*: print_string, \
    void*: print_ptr, \
    default: print_error \
)(x)

void print_int(int x) {
    printf("Int number: %d\n", x);
}
void print_long(long x) {
    printf("Long number: %ld\n", x);
}
void print_float(float x) {
    printf("Float: %f\n", x);
}
void print_double(double x) {
    printf("Double: %lf\n", x);
}
void print_string(char* x) {
    printf("String: %s\n", x);
}
void print_ptr(void* x) {
    printf("Number: %p\n", x);
}
void print_error(int x) {
    printf("unsupported type\n");
}


#define MAX(x, y) _Generic((x), \
    int: max_int, \
    float: max_float, \
    double: max_double, \
    unsigned int: max_u_int, \
    short: max_short, \
    long: max_long, \
    long long: max_long_long, \
    unsigned long long: max_u_long_long, \
    default: max_default \
)(x, y)

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
int max_default(int x, int y) {
    printf("Unsupported type\n");
    return 0;
}

#define IS_INTEGER(x) _Generic((x), \
    char: is_char, \
    int: is_int, \
    short: is_short, \
    long: is_long, \
    unsigned int: is_u_int, \
    unsigned short: is_u_short, \
    unsigned long: is_u_long, \
    default: is_integer_default \
)(x)

char is_char(char x) {
    return 1;
}
int is_int(int x) {
    return 1;
}
short is_short(short x) {
    return 1;
}
long is_long(long x) {
    return 1;
}
unsigned int is_u_int(unsigned int x) {
    return 1;
}
unsigned short is_u_short(unsigned short x) {
    return 1;
}
unsigned long is_u_long(unsigned long x) {
    return 1;
}
int is_integer_default(int x) {
    return 0;
}

#define FORMAT_SPECIFIER(x) _Generic((x), \
    int: "%d",                            \
    long: "%ld",                          \
    long long: "%lld",                    \
    unsigned int: "%u",                   \
    unsigned long: "%lu",                 \
    float: "%f",                          \
    double: "%lf",                        \
    char: "%c",                           \
    char*: "%s",                          \
    const char*: "%s",                    \
    default: "%p"                         \
)

#define PRINT_DIRECT(x) do { \
    printf(FORMAT_SPECIFIER(x), (x)); \
    printf("\n"); \
} while(0)

int main() {
    int x = 10;
    int y = 15;
    PRINT_VALUE(x);
    printf("Max value between %d and %d: ", x, y);
    PRINT_VALUE(MAX(x, y));
    PRINT_DIRECT(x);
}