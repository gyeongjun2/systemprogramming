#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

	int fd1, fd2,n;

	char buf[128];

	fd1 = open(argv[1],O_RDONLY);

	fd2= open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666);

	while((n = read(fd1,buf, sizeof(buf)))>0){
		write(fd2, buf, n);
	}


	


} 
