#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(){

	int status=0, pid;



	printf("P: %d, ppid=%d\n", getpid(),getppid());

	pid = fork();
	
	if(pid==0){	//child
		
		printf("C: %d, ppid=%d\n",getpid(),getppid());
		execl("/bin/date","date",(char*)0);
		exit(127);
	}

	wait(&status);
	printf("parent exit\n");
	exit(0);

}
