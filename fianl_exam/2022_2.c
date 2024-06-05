#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void *func(void *arg){

	int *val = malloc(sizeof(int));
	char *str = (char*)arg;
	
	if(val==NULL){
		perror("malloc: ");
		exit(2);
	}
	
	printf("%s\n", str);

	*val = strlen(str);

	return (void*)val;
}


int main(int argc, char *argv[]){

	pthread_t t1;
	int *ret;
	char *str = argv[1];

	if(pthread_create(&t1,NULL, func, (void*)str)!=0){
		perror("pthread_create(): ");
		exit(1);

	}

	if(pthread_join(t1,(void**)&ret));

	printf("%d\n", *ret);
	free(ret);
	exit(0);


}
