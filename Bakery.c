#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

enum boolean{false, true};
typedef enum boolean boolean;

pthread_t *t;
boolean *chosing; 
int *number, **temp, n;

void *Bakery(void *);
int Max(int *, int);

int main(){

int i;

	printf("Numero di threads: ");
	scanf("%d", &n);
	
	chosing = (boolean *) malloc(n*sizeof(boolean));
	number = (int *) malloc(n*sizeof(int));
	temp = (int **) malloc(n*sizeof(int*));
	t = (pthread_t *) malloc(n*sizeof(pthread_t));

	for(i=0; i<n; i++){
		chosing[i] = false;
		number[i] = 0;
	}

	for(i=0; i<n; i++){
		temp[i] = (int *) malloc(sizeof(int));
		*temp[i] = i;
		pthread_create(&t[i], NULL, Bakery, (int *)temp[i]);
	}

	for(i=0; i<n; i++) pthread_join(t[i], NULL);
}

void *Bakery(void *arg){

int i = *(int *)arg;
int j;
	
	for(; ;){

		chosing[i] = true;
		number[i] = Max(number, n) +1;
		chosing[i] = false;

		for(j=0; j<n; j++){

			while(chosing[j]);
			while(number[j] != 0 && ((number[j]<number[i]) || (number[j] == number[i] && j<i)));

		}
		
		printf("\nNumero del thread %d: %d\n", i, number[i]);
		sleep(1);
		number[i] = 0;

	}


}

int Max(int *array, int n){

int i, max = -1;

	for(i=0; i<n; i++)
		if(array[i]>max)
			max = array[i];

	return max;
}
