#include <stdio.h>
#include <stdint.h>


#define SWAP(a, b) do { \
	typeof(a) tmp = (a); \
	(a) = (b); \
	(b) = (tmp); \
} while(0)

#define PRINT_VALUE(val) ({	\
	__typeof__(val) _val = (val); \
	_Generic((_val), \
		int: printf("%d\n", (int)_val), \
		double: printf("%lf\n", (double)_val), \
		char*: printf("%s\n", (char*)(uintptr_t)_val), \
		default: printf("Unknown type\n") \
); \
})


void task2() {
	const int ci = 10;
	volatile int vi = 20;
	const volatile int cvi = 30;

	typeof_unqual(ci) x = ci;
	typeof_unqual(vi) y = vi;
	typeof_unqual(cvi) z = cvi;
	printf("Task2: %d %d %d\n", x + 2, y + 2, z + 2);
}

int main()
{
	int x = 5; int y = 7;
	task2();
	printf("Before swap (X, Y):\n");
	PRINT_VALUE(x);
	PRINT_VALUE(y);

	SWAP(x, y);
	printf("After swap (X, Y):\n");
	PRINT_VALUE(x);
	PRINT_VALUE(y);
}
