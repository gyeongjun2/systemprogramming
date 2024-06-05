#include "namedPipe.h"


int main(int argc, char *argv[]){

	struct msg ms;

	int fdpub, fdpriv, n;
	char buf[LINESIZE];

	int pid = getpid();

	sprintf(ms.pipe,"FIFO%d", pid);

	mknod(ms.pipe,S_IFIFO|0666,0);

	strcpy(ms.command, argv[1]);

	fdpub = open(PUBLIC, O_WRONLY);

	write(fdpub, (char*)&ms, sizeof(ms));

	close(fdpub);

	fdpriv = open(ms.pipe, O_RDONLY);

	while((n=read(fdpriv,buf,LINESIZE))>0){
		write(1,buf,n);
	}
	close(fdpriv);
	unlink(ms.pipe);
	exit(0);


}
