#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(){

	int pid, st;
	if(fork()==0){
		execl("./child","child",(char*)NULL);
		perror("fork error");
		exit(-1);
	}

	pid = wait(&st);
	printf("pid=[%d], status=[%x]", pid, st);

}
