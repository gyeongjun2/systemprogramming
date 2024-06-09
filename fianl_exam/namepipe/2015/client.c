#include "namedPipe.h"



int main() {
    int fdpub, fdpriv, n, status = 0, pid;
    char cmd[LINESIZE];
    char *path[] = {"/bin", "/usr/bin", NULL};
    char line[LINESIZE];
    char *argv[LINESIZE / 2];


    unlink(CLIENT);


    if (mkfifo(CLIENT, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("%% ");
        fflush(stdout);


        if (fgets(line, LINESIZE, stdin) == NULL) {
            perror("fgets");
            continue;
        }

        line[strlen(line) - 1] = '\0';

        int argc = 0;
        argv[argc] = strtok(line, " ");
        while (argv[argc] != NULL) {
            argc++;
            argv[argc] = strtok(NULL, " ");
        }

        int found = 0;
        for (int i = 0; path[i] != NULL; i++) {
            snprintf(cmd, sizeof(cmd), "%s/%s", path[i], argv[0]);
            if (access(cmd, X_OK) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            pid = fork();
            if (pid == 0) { 
                fdpub = open(PUBLIC, O_WRONLY);
                if (fdpub < 0) {
                    perror("open server pipe");
                    exit(EXIT_FAILURE);
                }

				close(1);
				dup(fdpub);
                close(fdpub);
                execv(cmd, argv);
                perror("execv"); 
                exit(EXIT_FAILURE);
            } else if (pid > 0) {
                wait(&status);

                fdpriv = open(CLIENT, O_RDONLY); 
                if (fdpriv < 0) {
                    perror("open client pipe");
                    continue;
                }

                char buf[LINESIZE];
                memset(buf,0x00,LINESIZE);
                while ((n = read(fdpriv, buf, sizeof(buf))) > 0) {
                    write(STDOUT_FILENO, buf, n);  
                }
                close(fdpriv);
            } else {
                perror("fork");
            }
        } else {
            printf("command not found\n");
        }
    }

    unlink(CLIENT);
    return 0;
}