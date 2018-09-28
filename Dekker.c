#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void *thread1(), *thread2();

pthread_t t1, t2;

int turn = 1, c1=1, c2 = 1;

int main(){

	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

}

void *thread1(){
	
	for( ; ; ){
		
		c1 = 0;
		while(c2 = 0){
			if(turn == 2){
				c1 = 1;
				while(turn == 2);
				c1 = 0;
			}
		}
		
		turn = 2;
		c1 = 1;
		printf("\nSono il primo thread\n");
		sleep(1);
	}
}

void *thread2(){
	
	for( ; ; ){
		
		c2 = 0;
		while(c1 = 0){
			if(turn == 1){
				c2 = 1;
				while(turn == 1);
				c2 = 0;
			}
		}
		
		turn = 1;
		c2 = 1;
		printf("\nSono il secondo thread\n");
		sleep(1);
		
	}
}
