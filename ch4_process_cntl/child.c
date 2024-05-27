#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	sleep(3);
	printf("child 2\n");
	exit(1);
}
