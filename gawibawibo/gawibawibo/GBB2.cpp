//����) ���������� �����//
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
		printf("����(1) ����(2) ��(3) : ");
		scanf("%d", &u);
		if(u>3)
		{
			i=i-1;
			printf("����� �Է��ϼ���Ѥ�\n");
			continue;
		}

	if(c==u)
	{
		printf("�����ϴ�.\n");
		lose=0;
		save++;
	}
	else if(c>u && c!=1)
	{
		printf("�����ϴ�.\n");
		lose++;
	}
	else if(c<u && u!=1)
	{
		printf("�̰���ϴ�.\n");
		lose=0;
		win++;
	}
	else if(c==1 && u==3)
	{
		printf("�����ϴ�.");
		lose++;
	}
	else if(c==3 && u==1)
	{
		printf("�̰���ϴ�.\n");
		lose=0;
		win++;
	}
	}


	printf("���� ��� : %d�� %d�� %d�� \n", win, save, lose);
	

	return 0;
}
