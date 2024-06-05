#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){

	int fd[2], status=0, p1,p2, n;
	char buf[128];

	if(pipe(fd)==-1){
		perror("pipe(): ");
		exit(1);
	}
	
	p1=fork();

	if(p1==0){
		close(1);
		dup(fd[1]);
		close(fd[0]);
		close(fd[1]);
		execl(argv[1],argv[1],(char*)0);

	}
	if(p2==0){
		close(0);
		dup(fd[0]);
		close(fd[0]);
		close(fd[1]);
		while((n=read(0,buf,sizeof(buf)))>0){
			write(1,buf, n);
		}
	}

	wait(&status);

	exit(0);

}
