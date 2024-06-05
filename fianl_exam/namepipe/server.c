#include "namedPipe.h"

int main(int argc, char *argv[]){

	int fdpub, fdpriv, fd, n, i;

	struct message msg;
	char line[LINESIZE];


	mknod(PUBLIC, S_IFIFO|0666,0);

	fdpub = open(PUBLIC, O_RDONLY);

loop:
	while(read(fdpub,(char*)&msg,sizeof(msg))>0){
		printf("Client Request Arrived.\n");
		fd = open(msg.filename,O_RDONLY);

		fdpriv = open(msg.privfifo, O_WRONLY|O_NDELAY);

		while((n=read(fd,line,LINESIZE))>0){
			write(fdpriv, line, n);
		}
		close(fd);
		close(fdpriv);
	}
	goto loop;


}
