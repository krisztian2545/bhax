#include <stdio.h>
#include <signal.h>

int jelkezelo(){
	printf("asd");
}

int main(){

	while(1){
		/*if(signal(SIGINT, jelkezelo())==SIG_IGN)
			signal(SIGINT, SIG_IGN);*/
		if(signal(SIGINT, SIG_IGN)!=SIG_IGN)
			signal(SIGINT, jelkezelo);
	}

	return 0;
}