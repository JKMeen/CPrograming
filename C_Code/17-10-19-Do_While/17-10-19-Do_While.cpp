#include <stdio.h>
#include <math.h>

#define scanf scanf_s

// 11부터 30까지 홀수 출력 :: do~while()문

void main(){
	int i = 11;
	do{
		printf("%d\n", i);
		i += 2;
	} while (i < 30);
}