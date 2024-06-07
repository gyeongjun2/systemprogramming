#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

	int status=0, pid;

	if(argc<3){
		printf("usage: %s infile outfile\n",argv[0]);
		exit(1);
	}

	pid = fork();

	if(pid==0){
		
		execl("/bin/cp","interest", argv[1],argv[2],(char*)0);
		exit(127);
	}
	wait(&status);

	printf("child exited\n");
	exit(0);
}
