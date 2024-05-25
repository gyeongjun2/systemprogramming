#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	int pid=0, status=0;

	//if child
	if((pid=fork())==0){
		execlp("./rcv_signal2", "rcv_signal", (char*)NULL);
		perror("execlp() : ");
		exit(2);	
	}
	//parent
	else if(pid>0){
		sleep(11);
		kill(pid, SIGINT);
		printf("[Parent]: SEND SIGINT\n");
		wait(&status);
		printf("[Parent]: Child killed by Parent.[%x]\n", status);

	}

}
