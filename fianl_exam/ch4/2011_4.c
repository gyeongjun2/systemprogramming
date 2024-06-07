#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){

	int status=0,pid;

	pid=fork();

	if(pid==0){

		printf("Hello, World\n");
		exit(10);
	}

	wait(&status);
	printf("P:child pid=[%d]\nchild exit_code=[%x]\n",pid,(status>>8));

}
