#include <stdio.h>

#define scanf scanf_s

void Swap(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void main(){
	int a, b;

	printf("a�� b�� �Է��Ͻÿ� >>> ");
	scanf("%d %d", &a, &b);

	Swap(&a, &b);

	printf("a : %d, b : %d\n", a, b);
}