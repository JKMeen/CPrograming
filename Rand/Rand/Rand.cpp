// 주사위 랜덤값 구하기//
#include <stdio.h>
#include <stdlib.h>  //랜덤을 쓰기 위해 꼭 입력
#include <time.h>

#define SIZE 6

int main()
{
	int freq[SIZE];
	srand(time(NULL));  // 현재 시간을 이용하여 매번 다른 난수 출력을 위함
	for(int i=0; i<6; i++){
		freq[i] = rand() % (SIZE)+1; // 0에서 SIZE까지 랜덤하는데, +1을 하면 1~SIZE까지 랜덤
		printf("주사위면 : %d \n", freq[i]);
	}
	return 0;
}