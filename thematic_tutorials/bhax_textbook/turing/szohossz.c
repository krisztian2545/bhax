#include <stdio.h>

int main(){

	int x = 1;
	int length = 0;

	do
		length++;
	while((x <<= 1));

	printf("A szóhossz mérete: %d\n", length);

	return 0;
}