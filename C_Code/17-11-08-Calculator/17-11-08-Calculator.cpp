#include <stdio.h>

#define scanf scanf_s

int Sum(int *a, int *b){
	return *a + *b;
}

int Sub(int *a, int *b){
	return *a - *b;
}

int Mul(int *a, int *b){
	return *a * *b;
}

float Div(int *a, int *b){
	return ((float)*a / (float)*b);
}

void main(){
	int input;
	for (; 1;){
		printf("1: ���ϱ�, 2:����, 3:���ϱ�, 4:������, -1:���� >>> ");
		scanf("%d", &input);
		if (input == -1)
			break;
		else {
			int a, b;
			switch (input){
			case 1: printf("�� �� ���� �� ���� �Է����ּ��� >>> ");
					scanf("%d %d", &a, &b);
					printf("%d + %d = %d\n\n", a, b, Sum(&a, &b));
					break;

			case 2: printf("�� ���� �� ���� �Է����ּ��� >>> ");
				scanf("%d %d", &a, &b);
				printf("%d + %d = %d\n\n", a, b, Sub(&a, &b));
				break;

			case 3: printf("���� ���� �� ���� �Է����ּ��� >>> ");
				scanf("%d %d", &a, &b);
				printf("%d + %d = %d\n\n", a, b, Mul(&a, &b));
				break;

			case 4: printf("���� ���� �� ���� �Է����ּ��� >>> ");
				scanf("%d %d", &a, &b);
				printf("%d + %d = %.2f\n\n", a, b, Div(&a, &b));
				break;
			}
		}
	}
}