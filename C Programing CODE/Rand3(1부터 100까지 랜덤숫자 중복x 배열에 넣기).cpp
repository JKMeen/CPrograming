//1���� 100���� �������� �ߺ����� �ʰ� �迭�� �ֱ�//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){

	srand((unsigned int)time(NULL));
	int num[100];

	for(int i=0; i<100; i++)
	{
		num[i] = rand() % 100+1;
		for(int j=0; j<i; j++)
		{
			if(num[i]==num[j])
			{
				num[i] = rand() % 100 +1;
				i--;
			}
		}
	}
	for(int i=0; i<100; i++) // Ȯ���ϱ� ���� ���ҹ�
	{
		for(int j=0; j<i; j++)
		{
			if(num[i]<num[j])
			{
				int tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
	for(int i=0; i<100; i++)
	{
		printf("%d\n", num[i]);
	}
}