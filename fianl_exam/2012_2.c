#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

	int status=0,pid;


	pid = fork();

	if(pid==0){

		execv(argv[1],&argv[1]);
		exit(127);
	}

	wait(&status);
	printf("Parent: child exit code = %x", status);
	exit(0);
}
