#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int);
void sigalrm_handler(int);

int mysleep(int);

void main(int argc, char *argv[]){

	int ret = 0;
	signal(SIGINT, sigint_handler);

	ret = mysleep(atoi(argv[1]));
	printf("remaining time : %d\n", ret);

	exit(0);

}

void sigint_handler(int sig){
	if(sig ==SIGINT)
		printf("\nRecevie SIGINT signal\n");
	}

int mysleep(int sec){

	int remain=0;
	void *old_set;

	old_set = signal(SIGALRM, sigalrm_handler);
	alarm(sec);
	pause();

	remain = alarm(0);
	signal(SIGALRM, old_set);
	return remain;

}

void sigalrm_handler(int){
	printf("Recevie SIGALRM signal\n");
	}
