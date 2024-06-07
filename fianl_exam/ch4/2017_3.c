#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char *argv[]){

	
	int status=0, pid;

	pid = fork();

	if(pid==0){
		
		execv("/bin/cmp",&argv[1]);
		exit(127);
	}
	wait(&status);

	printf("child exited\n");
	exit(0);

}
