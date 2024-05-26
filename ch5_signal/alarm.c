#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fun(int num){

	printf("SIGALARM signal.\n");
	exit(1);
}

int main(int argc, char *argv[]){

	signal(SIGALRM, fun);
	alarm(atoi(argv[1]));

	while(1);
}
