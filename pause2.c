#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void func(int);

int main(){

	signal(SIGALRM, func);
	alarm(1);
	
	pause(); //signal 발생했을때 함수가 세트되어있으므로 킵고잉한다.

	fprintf(stderr,"good\n"); //출력 O

}

void func(int sig){
	fprintf(stderr, "in handler\n");
}
