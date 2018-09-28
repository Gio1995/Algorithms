#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void *thread1(), *thread2();

pthread_t t1, t2;
int turn, flag[2] = {0, 0};

int main(){

	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}

void *thread1(){
	
	for(; ;){

		flag[0] = 1;
		turn = 1;
		
		while(flag[1] == 1 && turn == 1);
		
		flag[0] = 0;
		printf("\nSono il thread 1\n");
		sleep(1);
	}
		
}

void *thread2(){
	
	for(; ;){

		flag[1] = 1;
		turn = 0;
		
		while(flag[0] == 1 && turn == 0);
		
		flag[1] = 0;
		printf("\nSono il thread 2\n");
		sleep(1);
	}
		
}
