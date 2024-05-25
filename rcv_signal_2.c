#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define LIMIT_TIME 20

int main(){

	int rand_num;
	srand(getpid());
	rand_num = rand();
	rand_num = rand_num % LIMIT_TIME; //rand_num에는 0~19까지의 값이 들어가게됨 mod연산때매

	printf("\t[Child] : sleep random number : %d\n", rand_num);
	sleep(rand_num);
	printf("\t[Child] : process terminate! \n");
	exit(0x35);
}
