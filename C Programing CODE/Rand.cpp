// �ֻ��� ������ ���ϱ�//
#include <stdio.h>
#include <stdlib.h>  //������ ���� ���� �� �Է�
#include <time.h>

#define SIZE 6

int main()
{
	int freq[SIZE];
	srand(time(NULL));  // ���� �ð��� �̿��Ͽ� �Ź� �ٸ� ���� ����� ����
	for(int i=0; i<6; i++){
		freq[i] = rand() % (SIZE)+1; // 0���� SIZE���� �����ϴµ�, +1�� �ϸ� 1~SIZE���� ����
		printf("�ֻ����� : %d \n", freq[i]);
	}
	return 0;
}