#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


int command(char *cmd){

	int chpid, w, status;

	if((chpid=fork())==0){
		execlp("/bin/sh","sh","-c",cmd,(char*)0);
		exit(127);
	}

	while((w=wait(&status))!=chpid&&w!=-1)
		;
	if(w == -1)
		return -1;
	else return (status>>8);
	}


int main(){
	printf("\t%d\n", command("date > out; cat out"));
	printf("\t%d\n", command("date -x"));
	
	return 0;
}

