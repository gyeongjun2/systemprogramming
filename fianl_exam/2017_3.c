#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *func(void *arg){

	int *val = malloc(sizeof(int));
	
	*val = atoi((char*)arg);

	*val += 3;

	return (void*)val;

}





int main(int argc, char *argv[]){

	int n = argc-1;


	pthread_t t1[n+1];
	int *ret;

	if(argc<4){
	fprintf(stderr,"Usage ./a.out 1 2 3\n");
	exit(-1);
	}



	for(int i=1;i<=n;i++){
	if(pthread_create(&t1[i],NULL,func,argv[i])!=0){
		perror("pthread_create(): ");
		exit(1);
	}
	}

	for(int j=1;j<=n;j++){
		pthread_join(t1[j],(void**)&ret);
		printf("pthread_exit=[%d]\n", *ret);
	}

	exit(0);

}
