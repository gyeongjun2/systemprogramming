#include <stdio.h>
#include <unistd.h>

int main(){

	alarm(1);
	pause(); //시그널 발생 기다리는데 만약 default값이면 exit
	fprintf(stderr,"good\n");
}
