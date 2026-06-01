#include <stdio.h>

int checkbit(const int value, const int position) {
	return value & (1U << position);
}

int main()
{
	int n = 5;
	printf("%d\n", checkbit(n, 1));
	return 0;
}
