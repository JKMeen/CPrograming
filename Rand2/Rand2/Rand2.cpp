//����) �迭/ 50������ ���� ������ ��, ���, �ִ밪, �ּҰ� ���ϱ�//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, j;
	int tmp;
	int sum, max, min;
	double avg;
	int num[50];

	srand(time(NULL)); // �ð��� ���� ������ �ٲ��.

	for(i=0;i<50;i++)
		num[i]=rand()%101;  // num[i]�� 101������ ���� �� �ϳ��� �ִ´�.
                                             // (0~100���� ������)
	i=0;                 // i�� 0���� �ʱ�ȭ �Ѵ�. [��ø ����]
	while(i<50)           
	{
	for(j=0;j<5;j++)          //j�� 5���� 1�� �����ϴ� ����
	{
	printf("%5d", num[i]);    // 5���ͱ��� ���� num[i]�� ����Ѵ�
	i++;                    // I�� 1�� �����Ѵ�.
	}
	printf("\n");
	}

	for(i=0; i<50; i++)      
	{
		for(j=(i+1);j<50;j++)       // j�� 50���� 1�� �����Ѵ�. j�ʱⰪ I+1
		{
			if(num[i]>num[j])  
			{
				tmp=num[i];     
				num[i]=num[j];   
				num[j]=tmp;     // ����(�ִ밪�� �ּҰ��� ��������)
			}                   //(�̰� ���� ������ ���ڰ� ����)
		}                       
	}

	sum=0;           
	for(i=0;i<50;i++)        
		sum+=num[i]; // sum�� sum+num[i]���� ������.(50���� ���ڸ� �� ���Ѵ�)

	max=num[49]; 
	min=num[0];
	avg=sum/50.0;

	printf("��ü �� : %d\n", sum);
	printf("��ü ��� : %.2lf\n", avg);
	printf("�ִ밪 : %d\n", max);
	printf("�ּҰ� : %d\n", min);

	return 0;
}