#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int sec;

void handler(int sig);

int main(int argc, char *argv[]){

	int pid, status=0;

	sec = atoi(argv[2]);
	
	pid=fork();

	if(pid==0){

		execl(argv[1], argv[1],(char*)0);
		exit(127);

	}
	alarm(sec);
	signal(SIGALRM, handler);

	if(wait(&status)!=-1){
		alarm(0);
		printf("Parent: child exit within %d seconds\n", sec);
		exit(0);
	}

}

void handler(int sig){
	if(sig==SIGALRM){
		printf("Parent: child killed after %d seconds\n", sec);
		exit(0);
	}

}
