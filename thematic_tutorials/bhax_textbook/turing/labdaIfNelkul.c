#include <stdio.h>
#include <math.h>

#define width 80
#define height 24

void draw(int x, int y){

	for(int i = 0; i < y; i++) printf("\n");
	for(int k = 0; k < x; k++) printf(" ");
	printf("@\n");

}

int main(){

	int x = 1;
	int y = 1;

	while(1){

		system("clear");
		draw(abs(width-(x++%(width*2))), abs(height-(y++%(height*2))));
		usleep(50000);
		
	}

	return 0;
}