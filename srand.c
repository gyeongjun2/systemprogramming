#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(){

	srand(getpid());
	printf("%d\n", rand());
	printf("%d\n", rand());

}
