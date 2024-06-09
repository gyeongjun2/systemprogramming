#include "namedPipe.h"


int main() {
    int fdpub, fdpriv, pid, status = 0;
    char buf[LINESIZE];


    unlink(PUBLIC);


    if (mkfifo(PUBLIC, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    while (1) {

        fdpub = open(PUBLIC, O_RDONLY);
        if (fdpub < 0) {
            perror("open server pipe");
            exit(EXIT_FAILURE);
        }

        printf("Server: Waiting for input...\n");
        fflush(stdout);

		pid = fork();
		if(pid==0){
			close(0);
			dup(fdpub);
			close(fdpub);

			fdpriv = open(CLIENT, O_WRONLY);
			close(1);
			dup(fdpriv);
			close(fdpriv);
            execl("/bin/sort", "sort", (char *)0); 
            perror("execl"); 
            exit(127);

		}
		wait(&status);

        close(fdpub); 
    }

    unlink(PUBLIC); 
    return 0;
}