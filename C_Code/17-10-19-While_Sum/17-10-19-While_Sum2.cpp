#include <stdio.h>
#include <math.h>

#define scanf scanf_s

// 11���� 30���� Ȧ�� ��� :: do~while()��

void main(){
	int a, b = 0;

	printf("[a���� b������ �� ��� ���α׷�]\n\n");

	while (b != -1){
		int sum = 0;

		
		printf("���� a, b �Է�(a < b) >>> ");
		scanf("%d %d", &a, &b);

		if (b == -1){
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else if (a < b){
			for (int i = a; i <= b; i++){
				sum += i;
			}

			printf("%d���� %d������ �� >>> %d\n\n", a, b, sum);
		}
		else {
			printf("����! a�� b���� Ů�ϴ�.\n\n");
		}
	}
}