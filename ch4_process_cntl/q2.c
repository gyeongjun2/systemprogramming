#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

	int child1, child2, pid, status=0;

	if((child1=fork())==0){
		execl("/bin/date","date",(char*)0);
	}
	if((child2=fork())==0){
		execl("/bin/date","date","-x",(char*)0); //없는 옵션 주기
	}

	printf("\tParent: waiting for children\n");

	while((pid=wait(&status))!=-1){ // -1이 반환되면 while 종료 -> 자식이 다 죽음
		if(pid==child1)
			printf("\tParent: first child: %d-->정상 종료 0\n",(status>>8));
		else if(pid==child2)
			printf("\tParent: second child: %d-->강제 종료 1\n",(status>>8));
	}

	printf("\tParent: allchildren terminated\n");
	exit(0);
}
