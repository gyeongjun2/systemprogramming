#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>


int main(int argc, char *argv[]){

	int status=0, pid;

	pid = fork();

	if(pid==0){
		int fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0666);
		close(1);
		dup(fd);
		close(fd);
		printf("C: PPID=[%d], UID=[%d], GID=[%d]\n",
							getppid(), getuid(), getgid());
		exit(0);
	}

	wait(&status);

	printf("P: PID=[%d], UID=[%d], GID=[%d]\n",getpid(), getuid(), getgid());
	exit(0);

}
