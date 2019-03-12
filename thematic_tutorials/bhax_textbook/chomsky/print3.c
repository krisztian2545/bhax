#include <stdio.h>

int f(int *x){
	return *x+1;
}

int main(){

	int a = 0;

	printf("%d %d", f(&a), a);

	return 0;
}