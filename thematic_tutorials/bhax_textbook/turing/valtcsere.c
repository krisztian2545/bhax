#include <stdio.h>

int main(){

	int a = 3;
	int b = 8;

	printf("a = %d\nb = %d\n", a, b);

	a = a + b;
	b = a - b;
	a = a - b;

	printf("a = %d\nb = %d\n", a, b);

	return 0;
}