//독학) 문제 / while문, switch문//

#include <stdio.h>

int main()
{
	int a=0;
	int b=0;

	printf("맞출 때까지 계속되는 퀴즈 퀴즈!\n");
	printf("한남대교의 길이는 몇M일까요~?\n");

	while(1)
	{
		a++;
		scanf("%d", &b);

		if(b==915)
			break;
		else if(b<915)
			printf("그것보다 길어!\n");
		else
			printf("그것보다 짧아!\n");

		printf("다시 입력해! \n");
	}

	switch(a)
	{
	case 1:
		printf("정답! 한번에 맞췄네?? 대단해! 짱!! \n");
		break;
	case 5:
		printf("정답이야! 가물가물해도 기억하고있네?! \n");
		break;
	case 10:
		printf("정답이야. 잘찍었구나? \n");
		break;
	default:
		printf("정답인데.. 너 진짜 멍청하다... \n");
		break;
	}

	return 0;

}