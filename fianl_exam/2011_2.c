#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig){

	if(sig==SIGALRM){
		printf("Timeout\n");
		exit(0);
	}

}



int main(int argc, char *argv[]){

	int time = atoi(argv[1]);

	alarm(time);

	signal(SIGALRM, handler);
	signal(SIGINT, SIG_IGN);
	
	pause();

}
