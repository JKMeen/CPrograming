#include <stdio.h>
#include <math.h>

#define scanf scanf_s

// 11���� 30���� Ȧ�� ��� :: do~while()��

void main(){
	int i = 11;
	do{
		printf("%d\n", i);
		i += 2;
	} while (i < 30);
}