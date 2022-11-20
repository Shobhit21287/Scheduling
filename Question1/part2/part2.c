#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/wait.h>

int main(){
	char *arr[] = {"bash.sh",NULL};
	
	pid_t first,second;
	clock_t start,end;
	double final;
	
	int array[3];
	
	start = clock();

	first = fork();
	second = fork();

	if(first > 0 && second == 0){
		execv("./bash.sh",arr);
		printf("bruh\n");
	}
	else if(first == 0 && second > 0){
		execv("./bash.sh",arr);
		printf("bruh2\n");
	}
	else if(first == 0 && second == 0){
		execv("./bash.sh",arr);
		printf("bruh3\n");
	}
	else{
		waitpid(first,&array[0],0);
		end = clock();
		final = (double)(end - start) / CLOCKS_PER_SEC;
		waitpid(second,&array[1],0);
		end = clock();
		final = (double)(end - start) / CLOCKS_PER_SEC;
		waitpid(second + 1,&array[2],0);
		end = clock();
		final = (double)(end - start) / CLOCKS_PER_SEC;
	}
	return 0;
}
