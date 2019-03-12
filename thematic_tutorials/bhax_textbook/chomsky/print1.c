#include <stdio.h>

int f(int x, int y){
	return x + y;
}

int main(){
	
	int a = 0;

	printf("%d %d", f(a, ++a), f(++a, a));

	return 0;
}