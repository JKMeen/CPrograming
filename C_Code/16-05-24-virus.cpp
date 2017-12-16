/*	세균이 1시간마다 4배씩 증가한다고 가정하자. 이 세균 10마리를 배양하면 7시간 후의 세균의 수는 얼마나 될까?
	역시 지수 함수나 로그 함수를 이용하지 말고 반복 구조만을 사용하여서 해결하여 보자. */

#include <stdio.h>

void main()
{
	int virus;
	while (1)
	{
		printf_s("세균 개체 수 : ");
		scanf_s("%d", &virus);
		if (virus < 0) break;

		for (int i = 1; i <= 7; i++)
		{
			virus *= 4;
		}

		printf("7시간 후의 세균의 수 : %d\n", virus);
	}
}