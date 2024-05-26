#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

#define MAX_COUNT 100

int call_count = 0;

void sigalrm_signalhandler(int);

int main(){

	struct itimerval value;
	signal(SIGALRM, sigalrm_signalhandler);

	value.it_value.tv_sec = 5L;
	value.it_value.tv_usec = 0L;
	value.it_interval.tv_sec = 1L;
	value.it_interval.tv_usec = 0L;

	setitimer(ITIMER_REAL, &value, NULL);

	while(call_count<=5);

	printf("Terminate process!!!\n");

}

void sigalrm_signalhandler(int sig){

	struct itimerval o_value;
	
	if(sig==SIGALRM){
		printf("Recevie SIGALRM\n");
		call_count++;
		getitimer(ITIMER_REAL, &o_value);
		printf("tv_sec:%ld, \ttv_usec:%ld\n",
				o_value.it_value.tv_sec, o_value.it_value.tv_usec);
	}


}
