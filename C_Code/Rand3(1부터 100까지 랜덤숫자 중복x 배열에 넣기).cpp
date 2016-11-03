//1부터 100까지 랜덤값을 중복되지 않게 배열에 넣기//
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
	for(int i=0; i<100; i++) // 확인하기 위한 스왑문
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