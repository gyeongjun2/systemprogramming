#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

	int fd[2], fd1, status=0, pid, n;
	char buf[512];

	pipe(fd);

	fd1 = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0666);

	pid=fork();

	if(pid==0){
		int len = argc-1; //argument number argv[1]~...argv[n]
		close(1);
		dup(fd[1]);
		close(fd[0]);
		close(fd[1]);
		execv(argv[2],&argv[3]);
		exit(128);

	}

	close(fd[1]);
	wait(&status);

	while((n=read(fd[0],buf,sizeof(buf)))>0){
		write(fd1,buf,n);
	}
	close(fd[0]);
	close(fd1);
	exit(0);


}
