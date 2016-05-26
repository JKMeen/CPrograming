/*
	종이를 한번 접으면 면적이 1/2로 줄어든다. 종이를 몇 번 접어야 원래 면적의 1/100로 줄어드는가?
	역시 로그 함수나 지수 함수를 사용하지 말고 반복 구조를 이용하여서 해결하여 보자.
*/
#include <stdio.h>

void main()
{
	int count=0; //몇번 접었는지 카운트
	int num=100; // 입력받는 면적
	int n; // 줄어들 숫자

	printf("1/100 : %d\n", num/100);

	n = num;
	
	while(1)
	{
		n = n/2;
		printf("n = %d \n", n);
		if( n <= num/100) 
			break;
		count++;
	}

	printf("%d번 접어야함.", count);
}