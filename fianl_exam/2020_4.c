#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void *func(){

	printf("This is thread\n");
	sleep(1);

}




int main(){

	pthread_t t1;
	int *ret;

	if(pthread_create(&t1,NULL, func, NULL)!=0){
		perror("pthread_create(): ");
		exit(1);
	}

	if(pthread_join(t1,(void**)0)!=0){
		perror("pthread_join(): ");
		exit(2);
	}

	printf("OK\n");
	exit(0);
	
	


}
