#include "namedPipe.h"


int main(int argc, char *argv[]){

	int fdpub, n;

	char buf[LINESIZE];


	fdpub = open(PUBLIC, O_WRONLY);
	
	write(fdpub,argv[1],strlen(argv[1])+1);
	
	close(fdpub);

	fdpub = open(PUBLIC, O_RDONLY);

	while((n=read(fdpub,buf,LINESIZE))>0){
		write(1, buf, n);
	}
	close(fdpub);
	exit(0);
}
