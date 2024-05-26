#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MSGSIZE 20


int main(){

	int fd[2], pid;
	
	char msgin[MSGSIZE];
	char msgout[MSGSIZE] = "\nHello, world\n";
	
	if(pipe(fd)==-1){
		fprintf(stderr, "error occured\n");
		exit(1);
	}

	if((pid=fork())>0){	//parent
		close(fd[0]);	// 부모프로세스에서 read 닫기
		write(fd[1], msgout, MSGSIZE);
	}
	else if(pid==0){
		close(fd[1]);
		read(fd[0], msgin, MSGSIZE);
		puts(msgin);
	}


}
