#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void main(){
	int x, y;
	int point_x, point_y;
	int count = 0;

	srand((unsigned)time(NULL));

	// 랜덤 지점
	do {
		x = rand() % 10;
		y = rand() % 10;
	} while (x == y);

	printf("정답 좌표 :: ( %d , %d )\n", x, y);

	// 10회 반복
	for (int i = 0; i < 10; i++){
		// 입력 창
		printf("x, y 입력 >>> ");
		scanf("%d, %d", &point_x, &point_y);

		// 게임 종료
		if (point_x == x && point_y == y)
			break;
		else if (abs(x - point_x + y - point_y) == 0){
			cout << "놉!";
		}
		else {
			for (int j = 0; j < abs(x - point_x + y - point_y); j++){
				cout << "삑-\a";
			}
		}
		count++;
		printf("\n");
	}

	if (count < 10)
		printf("Game Win!\n");
	else
		printf("Game Lose...\n");
}

/*#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void main(){
	int x, y;
	int point_x, point_y;
	int count=0;

	srand((unsigned)time(NULL));

	// 랜덤 지점
	do {
		x = rand() % 10;
		y = rand() % 10;
		cout << x << y << endl;
	} while (x == y);
	// 10회 반복
	for (int i = 0; i < 10; i++){
		// 입력 창
		cout << "x, y 입력 >>> ";
		cin >> point_x >> point_y;
		
		// 게임 종료
		if (point_x == x && point_y == y)
			break;
		else if (abs(x - point_x + y - point_y) == 0){
			cout << "놉!";
		} else {
			for (int j = 0; j < abs(x - point_x + y - point_y); j++){
				cout << "삑-\a";
			}
		}
		count++;
		cout << endl;
	}

	if (count <10)
		cout << "Game Win!" << endl;
	else
		cout << "Game Lose.." << endl;
}*/


//int a = 0;
//int b = 0;
//int max = 0;
//int size = 0;
//
//cout << "Input Num 2" << endl;
//
//cin >> a;
//cin >> b;
//
//if (a > b)
//size = b;
//else
//size = a;
//
//for (int i = 2; i < size; i++){
//	if (a % i == 0 && b % i == 0){
//		max = i;
//	}
//}
//
//cout << "최대 공약수" << max << endl;

/*int c = 5;
for (int i = 10; i > 0; i -= c){
c--;
for (int k = 1; k < 10; k++){
for (int d = i; d > i - c; d--){
cout << d << " * " << k << " = " << d * k << "\t";
}
cout << "\n";
}
cout << "\n";
}*/