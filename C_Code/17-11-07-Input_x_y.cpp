#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 타입 이름(){} :: 함수
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

	printf("a와 b의 합은 >>> %d\n", c);
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
//		printf("5(up) 1(left) 2(down) 3(right)을 선택해서 입력해주세요! >>> ");
//		scanf_s("%d", &input);
//
//		switch (input){
//		case 5: y++; break; // UP
//		case 2: y--; break; // Down
//		case 1: x--; break; // Left
//		case 3: x++; break; // Right
//		default: printf("잘 못 입력하셨습니다.\n"); break;
//		}
//		input = 0;
//		printf("%d, %d의 현재 위치에 값은 >>> %d\n", x, y, a[x][y]);
//	}
//}