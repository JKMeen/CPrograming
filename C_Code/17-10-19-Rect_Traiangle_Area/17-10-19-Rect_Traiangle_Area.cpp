#include <stdio.h>
#include <math.h>

#define scanf scanf_s

void main(){
	int hight = 10;

	for (int i = 10; i <= 20; i += 2){
		printf("�簢����   ���� : %3d cm\n", hight);
		printf("�簢����   �غ� : %3d cm\n", i);
		printf("�簢����   ���� : %3d cm��\n", i*hight);

		printf("�ﰢ����   ���� : %3d cm\n", hight);
		printf("�ﰢ����   �غ� : %3d cm\n", i);
		printf("�ﰢ���� �밢�� : %2.2f cm\n", sqrtf(((i / 2)*(i / 2)) + (hight*hight)));
		printf("�ﰢ����   ���� : %3d cm��\n\n", i*hight / 2);
	}
}