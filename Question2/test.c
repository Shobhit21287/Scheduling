#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdio.h>
#define sys_twodcopy 548

int main(){
	double arr[4][4] = {{1.23,2.34,4.45,5.56},{6.67,7.78,8.89,9.101},{1.543,2.76543,0.2346,4.12351},{1,2,3,4}};

	double arr2[4][4];

	syscall(sys_twodcopy,arr,arr2,16);

	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			printf("%f	",arr2[i][j]);
		}
		printf("\n");
	}
}
