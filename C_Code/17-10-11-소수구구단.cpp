#include <stdio.h>

void main(){
	// 2�� ~ 11�� ���� ���ϴµ�,
	// �Ҽ� �� �ܸ� ��� ex) 2��, 3��, 5��, 7��, 11��

	int count = 0;
	
	// �ݺ���
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
printf("a�� b�� ���� �Է����ּ��� >> ");
	scanf("%d %d", &a, &b);
	printf("%d, %d \n", a, b);

	// ���(���ǹ�)
	if(a == 1){
		printf("���̴�!\n");
	} else {
		printf("Ʈ����ī��!\n");
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