#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ÿ�� �̸�(){} :: �Լ�
int add(int x, int y){
	int z;
	z = x + y;
	return z;
}

void main(){
	int a = 1;
	int b = 2;

	int c;
	c = add(a, b);

	printf("a�� b�� ���� >>> %d\n", c);
}


//#define scanf scanf_s

//void main(){
//	int a[10][10];
//	int x = 5, y = 5;
//	int input = 0;
//
//	srand((unsigned)time(NULL));
//
//	for (int i = 0; i < 10; i++){
//		for (int j = 0; j < 10; j++){
//			a[i][j] = rand() % 100;
//		}
//	}
//
//	while (input != 'z'){
//		printf("5(up) 1(left) 2(down) 3(right)�� �����ؼ� �Է����ּ���! >>> ");
//		scanf_s("%d", &input);
//
//		switch (input){
//		case 5: y++; break; // UP
//		case 2: y--; break; // Down
//		case 1: x--; break; // Left
//		case 3: x++; break; // Right
//		default: printf("�� �� �Է��ϼ̽��ϴ�.\n"); break;
//		}
//		input = 0;
//		printf("%d, %d�� ���� ��ġ�� ���� >>> %d\n", x, y, a[x][y]);
//	}
//}