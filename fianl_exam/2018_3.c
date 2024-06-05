#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *func(void *arg){

	int *val = malloc(sizeof(int));
	*val = atoi((char*)arg);
	
	//int *result = malloc(sizeof(int));
	//*result = (*val)*(*val);
	sleep(1);
	printf("%d\n", (*val)*(*val));
	pthread_exit((void*)0);

}



int main(int argc, char *argv[]){

	int n = argc-1;
	
	pthread_t thread[n+1];

	for(int i=1;i<=n;i++){
	pthread_create(thread,NULL,func,(void*)argv[i]);
	sleep(1);
	}

	for(int j=1;j<=n;j++){
	pthread_join(*thread, (void**)0);
	}
	
	pthread_exit((void*)0);

}
