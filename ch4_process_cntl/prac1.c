#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	int pid;

	if((pid=fork())==-1){
		perror("fork(): ");
		exit(-1);
	}

	if(pid==0){
		sleep(1);
		pid = getpid();
		printf("C: %d\n\n", pid);
		exit(0);
	
	}
	else{
	pid = getpid();
	printf("P: %d", pid);
	wait(0);

	}



}
