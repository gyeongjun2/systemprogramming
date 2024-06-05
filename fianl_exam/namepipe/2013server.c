#include "namedPipe.h"



int main(int argc, char *argv[]){

	int fdpub, fdpriv, fd, n;

	struct msg ms;

	char buf[LINESIZE];

	mknod(PUBLIC, S_IFIFO|0666,0);

	while(1){
		fdpub = open(PUBLIC, O_RDONLY);
		read(fdpub,(char*)&ms, sizeof(ms));
			if(fork()==0){
				fdpriv = open(ms.pipe,O_WRONLY);
				close(1);
				dup(fdpriv);
				close(fdpriv);
				char *cmd[] = {"/bin/sh","-c",ms.command,NULL};
				
				execv("/bin/sh",cmd);
				exit(127);
			}
		
		printf("\t%s%d\t:%s\n", ms.pipe,getpid(),ms.command);
		close(fdpub);

	}
	unlink(PUBLIC);
	return 0;
}
