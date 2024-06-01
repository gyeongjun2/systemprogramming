#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int sig){
	if(sig==SIGINT){
		printf("interrupt signal\n");
	}
	else if(sig==SIGQUIT){
		exit(19);
	}

}

int main(){

	int pid, status=0;

	pid = fork();

	if(pid==0){
		while(1){
			signal(SIGINT, signal_handler);
			signal(SIGQUIT, signal_handler);
		}
		
	}
	
	for(int i=0;i<3;i++){
		kill(pid, SIGINT);
		sleep(2.5);
	}
	kill(pid, SIGQUIT);

	wait(&status);
	printf("parent: child's exit_code=[%x]",(status>>8));

	return 0;


}
