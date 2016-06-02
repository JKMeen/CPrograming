#include <stdio.h>

int get_num();
int is_prime(int num);
int prime(int num);

void main(){
	int num = get_num();

	is_prime(num);
	printf("\n");
	prime(num);
}

int get_num(){
	int num;
	printf("���� �Է� : ");
	scanf("%d", &num );
	
	return num;
}

int is_prime(int num){
	int count=0;
	int i, j;
	for(i=1; i<=num; i++){
		for(j=1; j<i; j++){
			if(i%j == 0) count++;
		}
		if(count ==1) printf("[%d] ", i);
		count =0;
	}
}

int prime(int num){
	int i, count=0;
	for( i=2; i<num; i++){
		if (num % i ==0) count++;
	}
	if (count==0) printf("%d��(��) �Ҽ��Դϴ�.\n", num);
	else printf("%d��(��) �Ҽ��� �ƴմϴ�.\n", num);
}