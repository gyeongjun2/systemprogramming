#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TIMEOUT 10

int pid;

void sigalarm(int sig){

	printf("SIGALARM occurred\n");
	kill(pid, SIGKILL);
}

int main(int argc, char *argv[]){

	int status;
	if((pid=fork())==0){
		execvp(argv[1], &argv[1]); //argv[1] 실행해라.
		perror(argv[1]);//오류있다면 발생
		exit(127);
	}

	signal(SIGALRM, sigalarm);
	alarm(TIMEOUT);

	wait(&status);
	printf("Parent: timeremaining: %d\n", alarm(0));

	printf("Parent: child exit status value=[%x]\n", status);
}
