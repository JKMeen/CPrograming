#include <stdio.h>
#include <math.h>

#define scanf scanf_s

// 11부터 30까지 홀수 출력 :: do~while()문

void main(){
	int a, b = 0;

	printf("[a부터 b까지의 합 출력 프로그램]\n\n");

	while (b != -1){
		int sum = 0;

		
		printf("정수 a, b 입력(a < b) >>> ");
		scanf("%d %d", &a, &b);

		if (b == -1){
			printf("프로그램을 종료합니다.\n");
			break;
		}
		else if (a < b){
			for (int i = a; i <= b; i++){
				sum += i;
			}

			printf("%d부터 %d까지의 합 >>> %d\n\n", a, b, sum);
		}
		else {
			printf("오류! a가 b보다 큽니다.\n\n");
		}
	}
}