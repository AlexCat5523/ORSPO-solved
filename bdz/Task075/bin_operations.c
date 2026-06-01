#include <stdio.h>

int setbit(const int value, const int position) {
	return value | (1U << position);
}


int main()
{
	int n = 0;
	printf("Before: %d", n);
	printf("\nAfter: %d", setbit(n, 1));
	return 0;
}
