#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *func(void *arg){

	int value = *((int*)arg);
	
	int result = value * value;

	
	return (void*)(intptr_t)result;

}

int main(int argc, char *argv[]){


	pthread_t t1;
	
	void *retval;


	if(pthread_create(&t1,NULL,func,&argc)!=0){
		perror("pthread_create(): ");
		exit(1);
	}

	pthread_join(t1,(void**)&retval);

	printf("%d\n", (int)(intptr_t)retval);

	exit(0);


}
