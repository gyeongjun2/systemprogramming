#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){


	int fd[2], status=0, n;
	char buf[512];

	pipe(fd);

	if(fork()==0){
		close(1);
		dup(fd[1]);
		close(fd[0]);
		close(fd[1]);
		execl("/bin/cat","cat",argv[1],(char*)NULL);
		exit(127);
	}
	close(0);
	dup(fd[0]);
	close(fd[0]);
	close(fd[1]);

	wait(&status);
	
	while((n=read(0,buf,sizeof(buf)))>0){
		write(1,buf,n);
	}
	exit(0);


}
