#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){

	int status=0, p1,p2,p3,p4;

	
	p1=fork();

	if(p1==0){

		execl("/bin/echo","echo","one",(char*)0);
		exit(1);
	}

	p2=fork();
	if(p2==0){
		execl("/bin/echo","echo","two",(char*)0);
		exit(2);

	}
	
	p3=fork();
	if(p3==0){
		execl("/bin/echo","echo","three",(char*)0);
		exit(3);
	}

	p4=fork();
	if(p4==0){
		execl("/bin/echo","echo","four",(char*)0);
		exit(4);
	}
	
	int code;
	while((code = wait(&status))!=-1){
	if(p1==code){
		printf("one's exit_code=[%x]\n",status>>8);
	}
	else if(p2==code){
		printf("two's exit_code=[%x]\n", status>>8);
	}
	else if(p3==code){
		printf("three's exit_code=[%x]\n", status>>8);
	}
	else if(p4==code){
		printf("four's exit_code=[%x]\n", status>>8);
	}
	}

	exit(0);

}
