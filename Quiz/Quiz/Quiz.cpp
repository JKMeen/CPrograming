//����) ���� / while��, switch��//

#include <stdio.h>

int main()
{
	int a=0;
	int b=0;

	printf("���� ������ ��ӵǴ� ���� ����!\n");
	printf("�ѳ��뱳�� ���̴� ��M�ϱ��~?\n");

	while(1)
	{
		a++;
		scanf("%d", &b);

		if(b==915)
			break;
		else if(b<915)
			printf("�װͺ��� ���!\n");
		else
			printf("�װͺ��� ª��!\n");

		printf("�ٽ� �Է���! \n");
	}

	switch(a)
	{
	case 1:
		printf("����! �ѹ��� �����?? �����! ¯!! \n");
		break;
	case 5:
		printf("�����̾�! ���������ص� ����ϰ��ֳ�?! \n");
		break;
	case 10:
		printf("�����̾�. ���������? \n");
		break;
	default:
		printf("�����ε�.. �� ��¥ ��û�ϴ�... \n");
		break;
	}

	return 0;

}