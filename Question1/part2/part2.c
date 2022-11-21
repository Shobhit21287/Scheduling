#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/wait.h>
#include <sched.h>

/*clock_t start;
clock_t ends[3];*/
struct timespec start;
struct timespec ends[3];

char * arr[] = {"bash.sh",NULL};

pid_t forking(){
	pid_t new;
	new = fork();
	if(new > 1){
		return new;
	}
	else if(new == 0){ 
		execv("./bash.sh",arr);
		exit(0);
	}
	else{
		printf("error in forking\n");
	}
}

int main(){
	pid_t arr[3];
	pid_t arr2[3];
	int status[3];

	clock_gettime(CLOCK_REALTIME,&start);
	//start = clock();

	for(int i = 0 ; i < 3 ; i++){
		arr[i] = forking();
	}

	for(int i = 0 ; i < 3 ; i++){
		arr2[i] = waitpid(-1,&status[i],0);
		clock_gettime(CLOCK_REALTIME,&ends[i]);
	}

	double final;

	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			if(arr2[j] == arr[i]){
				printf("time taken by process %d :",j + 1);
			}
		}
		final = ((ends[i].tv_sec -start.tv_sec)*1000000000 + (ends[i].tv_nsec - start.tv_nsec))/1000000000 ;
		printf("%f\n",final);
	}
}
