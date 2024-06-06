#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

struct message{

	char pid[50];
	char command[100];


};

#define PUBLIC "SVR"
#define LINESIZE 1024
