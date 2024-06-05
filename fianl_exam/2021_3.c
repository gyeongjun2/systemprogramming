#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>


void *func(void *arg){
	
	int *num1 = malloc(sizeof(int));
	if(num1==NULL){
		perror("malloc");
		exit(3);
	}
	*num1 = atoi((char*)arg);

	int *result1 = malloc(sizeof(int));
	if(result1==NULL){
		perror("malloc");
		exit(4);
	}

	*result1 = (*num1)*(*num1);

	return (void*)result1;

}


int main(int argc, char *argv[]){

	pthread_t t1;
	int *ret;

	if(pthread_create(&t1,NULL,func,(void*)argv[1])!=0){
		perror("pthread_create(): ");
		exit(1);
	}

	if(pthread_join(t1,(void**)&ret)!=0){
		perror("pthread_join(): ");
		exit(2);
	}

	printf("Thread returned %d\n", *ret);
	free(ret);
	exit(0);


}
