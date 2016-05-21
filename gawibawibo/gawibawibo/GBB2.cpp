//독학) 가위가위보 만들기//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

int c, u, i;
int lose=0;
int win=0;
int save=0;

int main(void)
{
	int bo[SIZE] = {0};
	srand(time(NULL));

	for(i=0; i<6; i++)
	{
		c=rand()%3+1;
		printf("가위(1) 바위(2) 보(3) : ");
		scanf("%d", &u);
		if(u>3)
		{
			i=i-1;
			printf("제대로 입력하세요ㅡㅡ\n");
			continue;
		}

	if(c==u)
	{
		printf("비겼습니다.\n");
		lose=0;
		save++;
	}
	else if(c>u && c!=1)
	{
		printf("졌습니다.\n");
		lose++;
	}
	else if(c<u && u!=1)
	{
		printf("이겼습니다.\n");
		lose=0;
		win++;
	}
	else if(c==1 && u==3)
	{
		printf("졌습니다.");
		lose++;
	}
	else if(c==3 && u==1)
	{
		printf("이겼습니다.\n");
		lose=0;
		win++;
	}
	}


	printf("게임 결과 : %d승 %d무 %d패 \n", win, save, lose);
	

	return 0;
}
