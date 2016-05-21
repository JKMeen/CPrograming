//독학) 베이스볼 게임//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
	int com[3], pla[3];
	int strike=0, ball=0;
	srand(time(NULL));

	printf("베이스볼 게임!\n");

	for(int i=0; i<3; i++)
	{
		com[i]=rand()%9+1;
		printf("%d ", com[i]);
	}
	while(1)
	{
		printf("\n넘버 3개 입력 : ");
		for(int i=0; i<3; i++)
			scanf("%d", &pla[i]);
	
		if (com[0]==pla[0] && com[1]==pla[1] && com[2]==pla[2])
		{
			printf("정답입니다!!\n");
			break;
		}
		else
		{
			for(int i=0; i<3; i++)
			{
				for(int j=0; j<3; j++)
				{
					if(i==j)
					{
						if(com[i]==pla[i])
							strike++;
					}
					else
						if(com[i]==pla[j])
							ball++;
				}
			}
			printf("strike : %d,  ball : %d\n", strike, ball);
		
			strike = 0;
			ball = 0;

			continue;
		}
	}
}
