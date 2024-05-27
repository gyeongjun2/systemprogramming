#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){

	int w, status, pid;

	
	if((pid=fork())==0){
		
		execl("/bin/cat","mycat",argv[1],(char*)0);
		exit(127);
	
	}

	while((w=wait(&status))!=pid && w != -1)
		;
	printf("Parent: Child exit status=[%x]",(status>>8));
	exit(0);

}
