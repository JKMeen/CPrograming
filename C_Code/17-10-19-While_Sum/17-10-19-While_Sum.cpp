#include <stdio.h>
#include <math.h>

#define scanf scanf_s

// 11���� 30���� Ȧ�� ��� :: do~while()��

void main(){
	int n = 0;

	printf("[1���� n������ �� ��� ���α׷�]\n\n");

	while (n != -1){
		int sum = 0;

		
		printf("���� n �Է� >>> ");
		scanf("%d", &n);

		for (int i = 1; i <= n; i++){
			sum += i;
		}

		printf("1���� n������ �� >>> %d\n\n", sum);
	}
}