#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 50


int main(){

	int send_fd[2], rcv_fd[2], pid=0, size=0;

	char send_buf[MAX_SIZE], rcv_buf[MAX_SIZE];
	memset(send_buf,0x00, MAX_SIZE);
	memset(rcv_buf, 0x00, MAX_SIZE);

	if(pipe(send_fd)==-1){
		perror("pipe(): ");
		exit(1);
	}
	if(pipe(rcv_fd)==-1){
		perror("pipe(): ");
		exit(2);
	}

	if((pid=fork())==0){
		close(send_fd[1]);
		close(rcv_fd[0]);
		
		size = read(send_fd[0], rcv_buf, MAX_SIZE);
		printf("\t[Child]: Recevie Msg : %s\n", rcv_buf);
		write(rcv_fd[1], rcv_buf, size);
		printf("\t[Child]: Send Msg : %s\n", rcv_buf);
		exit(0);
	}
	else if(pid>0){
		close(send_fd[0]);
		close(rcv_fd[1]);
		size = read(0, send_buf, MAX_SIZE);	//this is test...를 읽고 저장
		write(send_fd[1], send_buf, size);
		printf("[Parent] : Send Msg : %s\n", send_buf);
		read(rcv_fd[0], rcv_buf, MAX_SIZE);	//child에서 쓴게 있으면 block되지않고 읽힘
		printf("[Parent] : Recevie Msg : %s\n", rcv_buf);
	}


}
