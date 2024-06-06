#include "namedPipe.h"


int main(int argc, char *argv[]){

	int fdpub, fdpriv, n;
	char buf[LINESIZE];
	struct message msg;

	strcpy(msg.command,argv[1]);
	if(argc>2){
		for(int i=2;i<argc;i++){
			strcat(msg.command," ");
			strcat(msg.command,argv[i]);
			}
		}
	//test
	printf("command=[%s]\n", msg.command);

	sprintf(msg.pid,"cli%d", getpid());

	mknod(msg.pid,S_IFIFO|0666,0);

	fdpub = open(PUBLIC,O_WRONLY); //open public pipe to write
	
	write(fdpub,(char*)&msg,sizeof(msg));

	fdpriv = open(msg.pid,O_RDONLY); //open cli pipe to read
	
	while((n=read(fdpriv,buf,LINESIZE))>0){
		write(1, buf, n);
		}

	unlink(msg.pid);
	exit(0);

}
