#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define scanf scanf_s

void main(){
	srand((unsigned)time(NULL));

	int random[5];

	for (int i = 0; i < 5; i++){
		random[i] = rand() % 10 + 1;
		for (int j = 0; j < i; j++){
			do{
				random[i] = rand() % 10 + 1;
			} while (random[i] == random[j]);
		}
	}

	for (int i = 0; i < 5; i++)
		printf("%d\n", random[i]);
}