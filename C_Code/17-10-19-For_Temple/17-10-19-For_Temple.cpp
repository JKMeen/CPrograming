#include <stdio.h>

#define scanf scanf_s

void main(){
	for (int i = 0; i < 100; i += 10){
		printf("ȭ���µ� %3d���� ������ %3d�Դϴ�.\n", i, (i-32) * 5 / 9);
	}
}