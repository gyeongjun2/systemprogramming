#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

	int status=0, i;
	int command = argc-1;

	int pid[command];

	for(i=1;i<=command;i++){
		pid[i]=fork();
		
		if(pid[i]==0){
			char *cmd = argv[i];
			execlp(cmd,cmd,(char*)NULL);
			exit(127); //if error occured
		}
			
	}
	
	int pid2;

	while((pid2 = wait(&status))>0){
		if(status==0){
			int success_exit = (status>>8);
			printf("child%d's exit_code : %d\n\n",pid2, success_exit);
		}
		else
			printf("child %d's exit_code : %d\n", pid2, (status>>8));
	}


}
