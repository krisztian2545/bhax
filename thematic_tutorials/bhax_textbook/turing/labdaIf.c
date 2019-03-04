#include <stdio.h>

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
	int a = 1;
	int b = 1;

	while(1){

		system("clear");

		if(x >= width  || x <= 0) a *= -1;
		if(y >= height || y <= 0) b *= -1;

		draw(x, y);
		x += a;
		y += b;

		usleep(15000);
		
	}

	return 0;
}