#include "namedPipe.h"



int main(int argc, char *argv[]){

	struct message msg;
	int n, fdpub, fdpriv;
	char line[LINESIZE];


	strcpy(msg.filename, argv[1]);
	sprintf(msg.privfifo, "Fifo%d", getpid());

	mknod(msg.privfifo,S_IFIFO|0666,0);
	
	fdpub = open(PUBLIC, O_WRONLY);

	write(fdpub,(char*)&msg, sizeof(msg));
	
	fdpriv = open(msg.privfifo, O_RDONLY);

	while((n=read(fdpriv, line, LINESIZE))>0){
		write(1,line,n);
	}
	close(fdpriv);
	unlink(msg.privfifo);
	exit(0);
}
