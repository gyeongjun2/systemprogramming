#include <stdio.h>
#include <setjmp.h>
#include <unistd.h>

jmp_buf env1;

void func(){

	longjmp(env1, 2);

}

int main(){

	int retcode;

	retcode = setjmp(env1);

	if(retcode==0){
		printf("%d\n", retcode);
	}
	else
		printf("-->%d\n", retcode);

	printf("3\n\n");
	sleep(1);
	func();


}
