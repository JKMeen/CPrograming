#include <stdio.h>

#define scanf scanf_s

void main(){
	for (int i = 9; i > 0; i--){
		for (int j = 1; j < i; j++){
			printf(" ");
		}
		for (int k = i; k < 10; k++){
			printf("%d", k);
		}
		printf("\n");
	}
}