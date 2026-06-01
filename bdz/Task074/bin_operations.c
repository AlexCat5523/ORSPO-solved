#include <stdio.h>

void bin(long unsigned int k, long unsigned int size)
{
	int res[size * 8];
	for (int i = size * 8 - 1; i >= 0; i--) {
		res[i] = k % 2;
		k = k / 2;
	}

	for (int i = 0; i < size * 8; i++) {
		printf("%d", res[i]);
	}
}

struct byte_s {
	unsigned a0 : 1;
	unsigned a1 : 1;
	unsigned a2 : 1;
	unsigned a3 : 1;
	unsigned a4 : 1;
	unsigned a5 : 1;
	unsigned a6 : 1;
	unsigned a7 : 1;
};

union code
{
	unsigned char letter;
	struct byte_s bitfield;
} byte;


int main()
{
	union code a, b;
    a.letter = 0b00000000;
    b.letter = 0b11111111;
    // a.letter = setbit(a.letter, 5);
    bin(5, 1); // печатает на экран число в двоичном виде
	return 0;
}
