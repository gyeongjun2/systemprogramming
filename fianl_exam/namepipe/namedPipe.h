#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct msg{

	char pipe[15];
	char command[100];
};

#define PUBLIC "Public"
#define LINESIZE 512
#define NUMTRIES 3

