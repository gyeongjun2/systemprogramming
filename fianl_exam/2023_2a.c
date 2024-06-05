#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *func(void *arg){

	int argc = *((int*)arg);
	int *result = malloc(sizeof(int));
	if(result==NULL){
		perror("malloc");
		exit(3);
	}
	*result = argc*argc;

	return (void*)result;

}



int main(int argc, char *argv[]){

	pthread_t t1;
	int *result;

	if(pthread_create(&t1, NULL,func,&argc)!=0){
		perror("pthread_create(): ");
		exit(1);
	}

	if(pthread_join(t1,(void**)&result)!=0){
		perror("pthread_join");
		exit(2);
	}

	printf("%d\n", *result);
	free(result);

	exit(0);


}
