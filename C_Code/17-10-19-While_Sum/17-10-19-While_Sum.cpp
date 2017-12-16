#include <stdio.h>
#include <math.h>

#define scanf scanf_s

// 11부터 30까지 홀수 출력 :: do~while()문

void main(){
	int n = 0;

	printf("[1부터 n까지의 합 출력 프로그램]\n\n");

	while (n != -1){
		int sum = 0;

		
		printf("정수 n 입력 >>> ");
		scanf("%d", &n);

		for (int i = 1; i <= n; i++){
			sum += i;
		}

		printf("1부터 n까지의 합 >>> %d\n\n", sum);
	}
}