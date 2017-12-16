#include <stdio.h>
#include <signal.h>
#include <unist.h>
#include <curse.h>

int main(){
	void f(int);
	int i;
	signal(SIGINT, SIG_IGN);
	printf("you can not stop me\n");
	for(i =0; i<5; i++){
		printf("Hello\n");
		sleep(1);
	}
}
void f(int signum){
	printf("OUCH!\n");
}
