#include "namedPipe.h"



int main(int argc, char *argv[]){

	int fdpub, fd, n, n2;

	char buf[LINESIZE];
	char buf2[LINESIZE];

	//"server" pipe create
	mknod(PUBLIC,S_IFIFO|0666,0);

	
	while(1){
	fdpub = open(PUBLIC, O_RDONLY);
	
	n=read(fdpub,buf,LINESIZE);
	buf[n]='\0';

	fd = open(buf,O_RDONLY);
	n2 =read(fd, buf2, LINESIZE);
	
	close(fdpub);
	fdpub = open(PUBLIC, O_WRONLY);
	write(fdpub, buf2, n2);
	close(fdpub);
	}

}
