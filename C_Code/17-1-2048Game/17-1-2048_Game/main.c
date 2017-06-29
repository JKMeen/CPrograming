#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//입력키의 아스키코드 저장
#define LEFT 75			// 왼쪽 방향키
#define RIGHT 77		// 오른쪽 방향키
#define UP 72			// 위쪽 방향키
#define DOWN 80			// 아래쪽 방향키
#define SPACEBAR 32		// 스페이스바

// 맵의 크기
#define Xsize 5
#define Ysize 5
#define Max_Size 4

struct point{
	int x, y;		// 점의 좌표
	int number;		// 점의 숫자
	int select;		// 점 선택 on / off
};

// 게임에서의 숫자 판
struct point object[Max_Size][Max_Size];	// 전체 오브젝트


// global 변수
int x = 1, y = 1;			// x, y좌표
int select_x = 1, select_y = 1; // 선택 x, y 좌표
int select_on = -1;			// 해당 좌표의 오브젝트 선택 (space바를 누르면 활성화)


// 함수
void Setting_Object();		// 오브젝트 초기 설정
void Select_Object();		// 오브젝트 선택 함수
void Draw_Object();			// 오브젝트 그리기 함수
void Clear_Object();		// 오브젝트 지우기 함수

void Draw_Map();			// 맵 그리기 함수

void PosXY(int x, int y);	// 위치 찾기 함수
void Hide_Cursor();			// 커서 삭제 함수
void Keyboard_Check();		// 키보드 체크 함수


// 메인 함수
void main(){
	Setting_Object();		// 오브젝트 숫자 설정
	Draw_Map();				// 맵 그리기
	//Draw_Object();			// 오브젝트 그리기

	// 블록 움직임 반복
	for (; 1;){
		Keyboard_Check();	// 키보드 체크 후 다시 그려줌
	}
}

// 키보드 체크 함수
void Keyboard_Check(){
	if (_kbhit()){
		int key = _getch();
		Clear_Object();
		if (key == 0xE0) { // 방향키
			key = _getch();
			switch (key){
			case LEFT:	if (x > 3)				x -= 3; break;	// 왼쪽 방향키
			case RIGHT: if (x < (Xsize - 2) * 3)	x += 3; break;	// 오른쪽 방향키
			case UP:	if (y > 1)				y--; break;	// 위쪽 방향키
			case DOWN:	if (y < Ysize - 1)		y++; break;	// 아래쪽 방향키
			}
			Draw_Object(x, y);
		}
		else { // 특수 키
			switch (key){
			case SPACEBAR:							// 선택, 스페이스바
				// 처음 선택 지정 (선택)
				if (select_on == -1){
					select_on = 1;
					select_x = x;
					select_y = y;
					object[y - 1][x / 3].select = 1;
					Draw_Object(x, y);
					Draw_Object(select_x, select_y);
				}

				// 선택 해제 - 다른 오브젝트 선택 (같은 숫자 / 숫자 합침)
				else {
					/*if (object[select_y - 1][select_x / 3].select == 1
					&& select_y != y && select_x != x)*/
					if (object[select_y - 1][select_x / 3].number == object[y - 1][x / 3].number){
						object[select_y - 1][select_x / 3].number += object[y - 1][x / 3].number;
						object[select_y - 1][select_x / 3].select = 0;
						select_on = -1;
						Draw_Object(select_x, select_y);
						Draw_Object(x, y);
					}
					else {
						//object[select_y - 1][select_x / 3].number += object[y - 1][x / 3].number;
						object[select_y - 1][select_x / 3].select = 0;
						select_on = -1;
						Draw_Object(select_x, select_y);
						Draw_Object(x, y);
					}
				}
				break;
			}
		}
	}
}

// 처음 오브젝트 세팅
void Setting_Object(){
	srand((unsigned)time(NULL)); // 랜덤 설정

	// 초기 숫자 지정
	for (int i = 0; i < Max_Size; i++){
		for (int j = 0; j < Max_Size; j++){
			// 위치 지정
			object[i][j].x = j;
			object[i][j].y = i;

			object[i][j].select = 0;

			// 숫자 지정
			object[i][j].number = 2;
			float random = rand() % 2 + 1;
			for (int k = 1; k < random; k++){
				object[i][j].number *= 2;
			}
		}
	}
}

// 전체 맵 그리기
void Draw_Map(){
	// 최 상단 줄
	for (int i = 0; i <= Xsize; i++){
		printf("▩");
	} printf("▩▩\n");

	// 중간 줄
	for (int i = 1; i < Ysize; i++){
		for (int j = 0; j <= Xsize; j++){
			if (j == 0) printf("▩");	// 첫번째 열과 마지막 열만 그려줌
			else if (j == Xsize) printf("▩");
			else {
				printf(" %d ", object[i - 1][j - 1].number);
			}
		}
		printf("\n");
	}

	// 마지막 줄
	for (int i = 0; i <= Xsize; i++){
		printf("▩");
	} printf("▩▩\n");


	// 2048 game
	for (int i = 0; i <= Xsize; i++){
		printf("**");
	} printf("****\n");
	printf("▩ 2048  GAME ▩ \n");
	for (int i = 0; i <= Xsize; i++){
		printf("▩");
	} printf("▩▩\n");
}


// 오브젝트 그리기
void Draw_Object(int x, int y){
	PosXY(y, x + 2);
	if (select_on == -1 && object[y - 1][x / 3].select == 1)
		printf(" %d ", object[y - 1][x / 3].number);
	else if (select_on == 1 && object[y - 1][x / 3].select == 1)
		printf("%d)", object[y - 1][x / 3].number);
}


// 오브젝트 지우기
void Clear_Object(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			PosXY(j + 1, i * 3 + 2);
			if (object[j][i].select == 0)
				printf(" %d ", object[j][i].number);
			else if (object[j][i].select == 1)
				printf("[%d]", object[j][i].number);
		}
	}
}

// 위치 찾기
void PosXY(int x, int y){
	COORD Pos = { y, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}