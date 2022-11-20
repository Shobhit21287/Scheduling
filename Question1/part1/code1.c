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
	clock_t s,t;
	s = clock();
	long int i = 1;
	for(long int j = 1 ; j < pow(2,32) ; j++){
		i++;
	}
	i = 0;
	for(long int j = 1 ; j < pow(2,32) ; j++){
		i++;
	}
	t = clock();
	double final = (double)(t - s) / CLOCKS_PER_SEC;
	printf("thread A : %f\n",final);
	return NULL;
}

void *countB(){
	pthread_attr_setschedparam(&attr2,&forB);
	clock_t s,t;
	s = clock();
	long int i = 1;
	for(long int j = 1 ; j < pow(2,32) ; j++){
		i++;
	}
	i = 0;
	for(long int j = 1 ; j < pow(2,32) ; j++){
		i++;
	}
	t = clock();
	double final = (double)(t-s) / CLOCKS_PER_SEC;
	printf("Thread B : %f\n",final);
	return NULL;
}

void *countC(){
	pthread_attr_setschedparam(&attr3,&forC);
	clock_t s,t;
	s = clock();
	long int i = 1;
	for(long int j = 1 ; j < pow(2,32) ; j++){
		i++;
	}
	i = 0;
	for(long int j = 0 ; j < pow(2,32) ; j++){
		i++;
	}
	t = clock();
	double final = (double)(t - s)/CLOCKS_PER_SEC;
	printf("Thread C : %f\n",final);
	return NULL;
}

void main(){
	pthread_t ThrA,ThrB,ThrC;

	forA.sched_priority = 0;
	forB.sched_priority = 99;
	forC.sched_priority = 99;

	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);
	pthread_attr_init(&attr3);

	pthread_attr_setinheritsched(&attr1,PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setinheritsched(&attr2,PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setinheritsched(&attr3,PTHREAD_EXPLICIT_SCHED);
	
	pthread_attr_setschedpolicy(&attr1,SCHED_OTHER);
	pthread_attr_setschedpolicy(&attr2,SCHED_RR);
	pthread_attr_setschedpolicy(&attr3,SCHED_FIFO);

	pthread_attr_setschedparam(&attr1,&forA);
	pthread_attr_setschedparam(&attr2,&forB);
	pthread_attr_setschedparam(&attr3,&forC);

	pthread_create(&ThrA,&attr1,countA,NULL);
	pthread_create(&ThrB,&attr2,countB,NULL);
	pthread_create(&ThrC,&attr3,countC,NULL);

	pthread_join(ThrA,NULL);
	pthread_attr_destroy(&attr1);
	pthread_join(ThrB,NULL);
	pthread_attr_destroy(&attr2);
	pthread_join(ThrC,NULL);
	pthread_attr_destroy(&attr3);
	
	return;

}


