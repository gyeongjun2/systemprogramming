#include "namedPipe.h"


int main(int argc, char *argv[]){

	int fdpub, fdpriv, n;
	char buf[LINESIZE];
	struct message msg;

	mknod(PUBLIC,S_IFIFO|0666,0);

	fdpub = open(PUBLIC, O_RDONLY);
	
loop:
	while(read(fdpub,(char*)&msg,sizeof(msg))>0){
		printf("arrived request\n");
		if(fork()==0){
			fdpriv = open(msg.pid, O_WRONLY);
			close(1);
			dup(fdpriv);
			close(fdpriv);
			
			char *arg[LINESIZE];
			char *cmd = strtok(msg.command," ");
			int i = 0;
			while(cmd!=NULL){
				arg[i++] = cmd; //arg[0] -> /bin/ls, arg[1] -> extra arg..
				cmd = strtok(NULL," ");
			}
			arg[i]=NULL;
			execv(arg[0],arg);
			exit(127);
		}
	}

	goto loop;


}
