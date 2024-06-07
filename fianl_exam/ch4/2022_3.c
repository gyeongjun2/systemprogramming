#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define LINESIZE 1024

int main(int argc, char *argv[]){

	int pid, status=0, fd,fd2, n;
	char buf[LINESIZE];

	pid = fork();
	if(pid==0){
		fd = open(argv[1],O_RDONLY);
		fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC,0666);

		while((n=read(fd,buf,LINESIZE))>0){
			write(fd2, buf, n);
		}
		exit(0);
	}

	wait(&status);
	printf("parent exit...\n");
	exit(0);

}
