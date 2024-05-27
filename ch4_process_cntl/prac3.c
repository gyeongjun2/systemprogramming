#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//execv를 사용
//int execv(const char *path, char *const argv[]);

int main(int argc, char *argv[]){

	int status, pid;

	if(fork()==0){
		execv(argv[1], &argv[1]);
		exit(1);
	}

	wait(&status);

	printf("Parent: child exit code = %x", status>>8);
	exit(0);

}
