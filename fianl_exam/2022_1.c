#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void handler(int sig){
	
		printf("interrupt signal\n");
		exit(0);
	

}

int main(int argc, char *argv[]){

	int i, pid, status=0;
	int sec = atoi(argv[1]);	
	
	if((pid=fork())==0){
		signal(SIGINT, handler);
		while(1){
		printf("OK\n");
		sleep(2);
		}
	}

	sleep(sec);
	kill(pid, SIGINT);
	wait(&status);

}
