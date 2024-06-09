#include "namedPipe.h"


int main(int argc, char *argv[]) {
    int fdpub, fdpriv, fd;
    char buf[LINESIZE];
    struct msg ms;

    mknod(PUBLIC, S_IFIFO | 0666, 0);
    fdpub = open(PUBLIC, O_RDONLY);
    fd = open("log", O_WRONLY | O_APPEND);

    while (1) {
        while (read(fdpub, (char*)&ms, sizeof(ms)) > 0) {
            if (fork() == 0) {
                
                signal(SIGINT, SIG_IGN);

                fdpriv = open(ms.pipe, O_WRONLY);
                close(1);
                dup(fdpriv);
                close(fdpriv);

                char *cmd = strtok(ms.command, " ");
                char *arg[LINESIZE];
                int i = 0;
                while (cmd != NULL) {
                    arg[i++] = cmd;
                    cmd = strtok(NULL, " ");
                }
                arg[i] = NULL;

                char *path[] = {"/bin/", "/usr/bin/", NULL};
                int found = 0;
                char command_path[LINESIZE];

                for (int j = 0; path[j] != NULL; j++) {
                    snprintf(command_path, sizeof(command_path), "%s%s", path[j], arg[0]);
                    if (access(command_path, F_OK) == 0) {
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    
					exit(1);
                }

                execv(command_path, arg);
                perror("execvp failed");
                exit(129);
            }

            if (fork() == 0) { 
                close(1);
                dup(fd);
                printf("\t%s\t:%s\n", ms.pipe, ms.command);
                close(fd);
                exit(0);
            }
        }
    }

    close(fdpub);
    close(fd);
    unlink(PUBLIC);

    return 0;
}
