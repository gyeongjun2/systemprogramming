#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){

	if(fork()==0){
		execl(argv[1],argv[1],(char*)NULL);
		printf("below child.\n");	//정상적인 경우 출력 x
	
	}
	else
		wait((int*)1);
		printf("Parent.\n");
}
