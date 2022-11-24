#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

pthread_attr_t attr1,attr2,attr3;
struct sched_param forA,forB,forC;

void *countA(){
	pthread_attr_setschedparam(&attr1,&forA);
	struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);
	long int i = 1;
	for(long int j = 1 ; j < pow(2,32) ; j++){
		i++;
	}
	i = 0;
	for(long int j = 1 ; j < pow(2,32) ; j++){
		i++;
	}
	clock_gettime(CLOCK_REALTIME,&end);
	double final =(double)((end.tv_sec - start.tv_sec)*1000000000 + (end.tv_nsec - start.tv_nsec))/1000000000;
	printf("thread OTHER : %f\n",final);
	return NULL;
}

void *countB(){
	pthread_attr_setschedparam(&attr2,&forB);
	struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);
	long int i = 1;
	for(long int j = 1 ; j < pow(2,32) ; j++){
		i++;
	}
	i = 0;
	for(long int j = 1 ; j < pow(2,32) ; j++){
		i++;
	}
	clock_gettime(CLOCK_REALTIME,&end);
	double final =(double) ((end.tv_sec - start.tv_sec)*1000000000 + (end.tv_nsec - start.tv_nsec))/1000000000;
	printf("Thread RR : %f\n",final);
	return NULL;
}

void *countC(){
	pthread_attr_setschedparam(&attr3,&forC);
	struct timespec start,end ;
	clock_gettime(CLOCK_REALTIME,&start);
	long int i = 1;
	for(long int j = 1 ; j < pow(2,32) ; j++){
		i++;
	}
	i = 0;
	for(long int j = 0 ; j < pow(2,32) ; j++){
		i++;
	}
	clock_gettime(CLOCK_REALTIME,&end);
	double final =(double)((end.tv_sec - start.tv_sec)*1000000000 + (end.tv_nsec - start.tv_nsec))/1000000000 ;
	printf("Thread FIFO : %f\n",final);
	return NULL;
}

void main(){
	pthread_t ThrA,ThrB,ThrC;
	
	struct sched_param forA,forB,forC;

	forA.sched_priority = 0;
	forB.sched_priority = 99;
	forC.sched_priority = 99;
	
	pthread_create(&ThrA,NULL,countA,NULL);
	pthread_setschedparam(ThrA,SCHED_OTHER,&forA);
	pthread_create(&ThrB,NULL,countB,NULL);
	pthread_setschedparam(ThrB,SCHED_RR,&forB);
	pthread_create(&ThrC,NULL,countC,NULL);
	pthread_setschedparam(ThrC,SCHED_FIFO,&forC);

	pthread_join(ThrA,NULL);
	pthread_join(ThrB,NULL);
	pthread_join(ThrC,NULL);
	
	return;

}
