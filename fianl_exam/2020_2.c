#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	int status=0, pid;

	pid = fork();

	if(pid==0){ //if child
		
		execl("/bin/ls","ls","-l",(char*)0);
		exit(127);
	}

	wait(&status);
	printf("parent: OK\n");
	exit(0);
}
