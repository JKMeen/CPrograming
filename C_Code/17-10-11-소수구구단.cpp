#include <stdio.h>

void main(){
	// 2단 ~ 11단 까지 구하는데,
	// 소수 인 단만 출력 ex) 2단, 3단, 5단, 7단, 11단

	int count = 0;
	
	// 반복문
	for(int i = 2; i < 101; i++){
		for (int j = 1; j < i; j++){
			if (i % j == 0){
				count++;  // 2 :: 1, 3 :: 1, 4 :: 2
			}
		}
		if(count == 1){
			printf(" <%d> \n", i);
			for (int j = 1; j < i; j++){
				printf("%d * %d = %d", i, j, i*j);
			}
		}
		count = 0;
	}	 
}




/*
int a;
	int b;
printf("a와 b의 값을 입력해주세요 >> ");
	scanf("%d %d", &a, &b);
	printf("%d, %d \n", a, b);

	// 제어문(조건문)
	if(a == 1){
		printf("명석이다!\n");
	} else {
		printf("트로피카나!\n");
	}*/

/*
int count = 0;

	for (int i=2; i<100; i++){
		for (int j=1; j<i; j++){
			if (i%j == 0){
				count++;
			}
		}
		if (count == 1){
			printf(" <%d> ", i);
		}
		count = 0;
	}

*/