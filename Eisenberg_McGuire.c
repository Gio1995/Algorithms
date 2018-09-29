#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

enum state {IDLE, WAITING, ACTIVE};
typedef enum state state;

state *flags;
pthread_t *t;
int **temp, turn = 0, n;

void *P(void *);

int main(){

	int i=0;

	printf("Insert the number of threads: ");
	scanf("%d", &n);

	flags = (state *) malloc(n*sizeof(state));
	t = (pthread_t *) malloc(n*sizeof(pthread_t));
	temp = (int **) malloc(n*sizeof(int *));
	
	
	for(i=0; i<n; i++) flags[i] = IDLE;
	for(i=0; i<n; i++){
		temp[i] = (int *) malloc(sizeof(int));
		*temp[i] = i;
		pthread_create(&t[i], NULL, P, (int *)temp[i]);
	}
	
	for(i=0; i<n; i++) pthread_join(t[i], NULL);

}

void *P(void *arg){

int i = *(int *)arg;
int j;

	for(; ;){
	
		do{
			flags[i] = WAITING;
			j = turn;

			while(j!=i){
				if(flags[j] != IDLE) 
					j = turn;
				else
					j = (j+1)%n;
			}

			flags[i] = ACTIVE;
			j = 0;

			while(j<n && (j == i || flags[j] != ACTIVE))
				j++;
			
		}while(i>=n && (turn == i || flags[turn] == IDLE));

		turn = i;
		printf("\nSono il thread numero %d\n", i);
		sleep(1);
		j = (turn + 1)%n;
		
		while(flags[j] == IDLE) j = (j + 1)%n;
		turn = j;
		flags[i] = IDLE;
	}
	pthread_exit(0);
}
