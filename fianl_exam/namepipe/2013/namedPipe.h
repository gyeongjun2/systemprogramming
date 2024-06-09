#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>

struct msg{

	char pipe[15];
	char command[100];

};

#define PUBLIC "public"
#define LINESIZE 512
