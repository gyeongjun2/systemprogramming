#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


void handler(int sig){
	if(sig==SIGALRM){
	printf("timeout\n");
	}
	else if(sig==SIGINT){
		printf("Goodbye\n");
		exit(0);
	}
	
}


int main(int argc, char *argv[]){

	struct itimerval t_val;
	
	t_val.it_value.tv_sec = atoi(argv[1]);
	t_val.it_value.tv_usec = atoi(argv[2]);
	t_val.it_interval.tv_sec = atoi(argv[3]);
	t_val.it_interval.tv_usec = atoi(argv[4]);
	setitimer(ITIMER_REAL, &t_val, NULL);
	signal(SIGALRM, handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler);
	while(1);
	pause();


}
