#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){

	int status=0, pid;

	pid = fork();

	if(pid==0){
		
		execl("/bin/ps","ps","-axl",(char*)NULL);
		exit(127);
	}

	wait(&status);

	printf("child exit_code=[%d]",status>>8);
	exit(0);

}
