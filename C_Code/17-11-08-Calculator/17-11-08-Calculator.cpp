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
		printf("1: 더하기, 2:빼기, 3:곱하기, 4:나누기, -1:종료 >>> ");
		scanf("%d", &input);
		if (input == -1)
			break;
		else {
			int a, b;
			switch (input){
			case 1: printf("더 할 숫자 두 개를 입력해주세요 >>> ");
					scanf("%d %d", &a, &b);
					printf("%d + %d = %d\n\n", a, b, Sum(&a, &b));
					break;

			case 2: printf("뺄 숫자 두 개를 입력해주세요 >>> ");
				scanf("%d %d", &a, &b);
				printf("%d + %d = %d\n\n", a, b, Sub(&a, &b));
				break;

			case 3: printf("곱할 숫자 두 개를 입력해주세요 >>> ");
				scanf("%d %d", &a, &b);
				printf("%d + %d = %d\n\n", a, b, Mul(&a, &b));
				break;

			case 4: printf("나눌 숫자 두 개를 입력해주세요 >>> ");
				scanf("%d %d", &a, &b);
				printf("%d + %d = %.2f\n\n", a, b, Div(&a, &b));
				break;
			}
		}
	}
}