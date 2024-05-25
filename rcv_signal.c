#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT 10

void sigint_signalhandler(int sig){
	printf("\t[Child] receive SIGINT\n");
	exit(25);//프로세스가 자의적으로 종료
}

int main(){

	int i=0;

	signal(SIGINT, sigint_signalhandler);//이게 없으면 시그널맞고 주금 -> return값은 sig번호

	for(i=1; i<MAX_COUNT; i++){
	
		printf("\t[Child] sleep count #%d\n", i);
		sleep(1);
	}

	printf("\t[Child] process terminate!\n");
	exit(0);
}
