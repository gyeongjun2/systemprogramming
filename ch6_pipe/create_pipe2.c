#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX 50

int main(int argc, char *argv[]){

	int fd[2], pid=0, size=0, status=0;

	char buf[MAX];
	memset(buf,0x00,MAX);

	if(pipe(fd)==-1){
		perror("pipe():");
		exit(1);
	}

	if(fork()==0){	//child 1
		close(0); //stdin 닫고
		dup(fd[0]); // fd[0]을 복제
		close(fd[0]);
		close(fd[1]);	//pipe 입출력 둘다 닫음
		size = read(0, buf, MAX);
		execlp(buf, buf, (char*)NULL); //buf의 내용 실행
		perror("execlp(): ");
		exit(3);
	}

	if(fork()==0){ //one more fork
		close(1); //stdout 닫기
		dup(fd[1]);
		close(fd[0]);
		close(fd[1]);
		printf("%s", argv[1]); //이게 pipe에 써짐
		fflush(stdout); //남은거 플러쉬
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	while(wait(&status)!=-1)
		;
	exit(0);

}
