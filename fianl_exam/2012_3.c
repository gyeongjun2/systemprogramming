#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){

	int fd[2], status=0, pid, n;
	char buf[512];
	pipe(fd);


	pid = fork();
	if(pid==0){
		close(1);
		dup(fd[1]);
		close(fd[1]);
		close(fd[0]);
		execl("/bin/cat", "cat", argv[1], 0);
		exit(127);
	}
	wait(&status);

	close(0);
	dup(fd[0]);
	close(fd[1]);
	close(fd[0]);

	while((n=read(0,buf,sizeof(buf)))>0){
		write(1,buf,n);
	}

	exit(0);
}
