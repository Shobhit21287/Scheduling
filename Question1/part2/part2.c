#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/wait.h>

clock_t start;
clock_t ends[3];

char * arr[] = {"./bash.sh",NULL};

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

	for(int i = 0 ; i < 3 ; i++){
		arr[i] = forking();
	}

	for(int i = 0 ; i < 3 ; i++){
		arr2[i] = waitpid(-1,&status[i],0);
		ends[i] = clock();
	}

	double final;

	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			if(arr2[j] == arr[i]){
				printf("time taken by process %d :",j + 1);
			}
		}
		final = (double)(ends[i] - start) / CLOCKS_PER_SEC ;
		printf("%f\n",final);
	}
}
