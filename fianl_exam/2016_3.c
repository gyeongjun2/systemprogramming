#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char *argv[]){


	int fd[2], status=0, pid, n;
	char buf[512];

	if(pipe(fd)==-1){
		perror("pipe(): ");
		exit(1);
	}

	pid = fork();

	if(pid==0){
		write(fd[1], argv[1], strlen(argv[1]));
		close(fd[0]);
		close(fd[1]);
		exit(0);
	}
	close(fd[1]);

	wait(&status);

	while((n=read(fd[0],buf,sizeof(buf)))>0){
		write(1,buf, n);
	}

	close(fd[0]);


}
