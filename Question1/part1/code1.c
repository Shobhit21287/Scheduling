#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

void * countA(){
    struct timespec start,end;
    clock_gettime(CLOCK_REALTIME,&start);
    long int i = 0;
    for(long int i = 0 ; j < pow(2,32) ; j++){
        i++;
    }
    clock_gettime(CLOCK_REALTIME,&end);
    double final = ((end.tv_sec - start.tv_sec)*1000000000 + (end.tv_nsec - start.tv_nsec))*1000000000 ;
    printf("Thread A : %f\n",final);
}

void * countB(){
    struct timespec start,end;
    clock_gettime(CLOCK_REALTIME,&start);
    long int i = 0;
    for(long int i = 0 ; j < pow(2,32) ; j++){
        i++;
    }
    clock_gettime(CLOCK_REALTIME,&end);
    double final = ((end.tv_sec - start.tv_sec)*1000000000 + (end.tv_nsec - start.tv_nsec))*1000000000 ;
    printf("Thread B : %f\n",final);
}

void * countC(){
    struct timespec start,end;
    clock_gettime(CLOCK_REALTIME,&start);
    long int i = 0;
    for(long int i = 0 ; j < pow(2,32) ; j++){
        i++;
    }
    clock_gettime(CLOCK_REALTIME,&end);
    double final = ((end.tv_sec - start.tv_sec)*1000000000 + (end.tv_nsec - start.tv_nsec))*1000000000 ;
    printf("Thread C : %f\n",final);
}
int main(){
    pthread thrA,thrB,thrC;
    struct sched_param fora,forb,forc;
    fora.sched_priority = 0;
    forb.sched_priority = 0;
    forc.sched_priority = 0;

    pthread_setschedparam(thrA,SCHED_OTHER,fora);
    pthread_setschedparam(thrB,SCHED_FIFO,forb);
    pthread_setschedparam(thrC,SCHED_RR,forc);

    pthread_create(&thrA,NULL,countA,NULL);
    pthread_create(&thrB,NULL,countB,NULL);
    pthread_create(&thrC,NULL,countC,NULL);
}
