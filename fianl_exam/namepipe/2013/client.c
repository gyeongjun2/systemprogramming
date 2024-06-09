#include "namedPipe.h"



int main(int argc, char *argv[]) {
    int fdpub, fdpriv, n;
    struct msg ms;
    char buf[LINESIZE];

    sprintf(ms.pipe, "FIFO%d", getpid());


    strcpy(ms.command, argv[1]);
    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            strcat(ms.command, " ");
            strcat(ms.command, argv[i]);
        }
    }
    mknod(ms.pipe, S_IFIFO | 0666, 0);

    fdpub = open(PUBLIC, O_WRONLY);
    write(fdpub, (char*)&ms, sizeof(ms));
    close(fdpub);

    fdpriv = open(ms.pipe, O_RDONLY);
    while ((n = read(fdpriv, buf, LINESIZE)) > 0) {
        write(1, buf, n);
    }
    close(fdpriv);
    unlink(ms.pipe);
    exit(0);
	}
