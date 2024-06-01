#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	int status=0, pid;

	pid = fork();

	if(pid==0){	// child
		
		execl("/bin/date", "date", "-u",(char*)0);
		exit(127);

	}
	
	wait(&status);
	printf("Child exit_code=[%d]\n",(status>>8));
	printf("child pid=[%d]", getpid());

}
