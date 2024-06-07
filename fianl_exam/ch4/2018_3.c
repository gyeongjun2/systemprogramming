#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char *argv[]){

	int status=0, pid;


	pid = fork();

	if(pid==0){	//if child

		execv(argv[1],&argv[1]);
		exit(127);
	}

	wait(&status);

	printf("parent exit\n");
	exit(0);

}
