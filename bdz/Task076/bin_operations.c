#include <stdio.h>

int unsetbit(const int value, const int position) {
	return value & ~(1U << position);
}

int main()
{
	int n = 5;
	printf("%d\n", unsetbit(n, 0));
	return 0;
}
