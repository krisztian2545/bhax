#include <stdio.h>

int f(int x){
	return x * x;
}

int main(){

	int a = 2;

	printf("%d %d", f(a), a);

	return 0;
}