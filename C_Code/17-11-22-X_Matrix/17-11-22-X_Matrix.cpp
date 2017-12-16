#include <stdio.h>

#define scanf scanf_s


void main(){
	int a[9][9];

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (i == j || i+j == 8)
				a[i][j] = 1;
			else
				a[i][j] = 0;

			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}