#include <stdio.h>                     //테트리스 만들기//
#include <windows.h>
#include <conio.h>

#define LEFT 75 //입력키의 아스키코드 저장
#define RIGHT 77
#define UP 72
#define DOWN 80

#define Xsize 20 /* 맵의 크기 */
#define Ysize 26

struct point { //각 블록 객체의 좌표
	int x, y;
};

//게임에서 사용되는 블록의 정의 [방향][각각 좌표]
point block[4][4] = { -1, 0, 0, 0, 1, 0, 0, -1, -1, 0, 0, -1, 0, 0, 0, 1, -1, 0, 0, 0, 1, 0, 0, 1, 0, -1, 0, 0, 0, 1, 1, 0 };

int x, y; //배열내에서의 좌표
int sh, n; //블록의 현재모양과 넘버

void clearBlock(); //블록 지움
void printBlock(); //블록 출력
void printMap(); /* 맵 그리기 */
void gotoxy(int x, int y); //해당위치를 찾아감
void noCursor(); //커서를 없앤다.

void main()
{
	int ch;
	x = 5; /*처음 좌표 */
	y = 2;
	noCursor(); /* 커서 지움 */
	printMap(); /* 맵 그리기 */
	printBlock(); /* 블록 출력 */

	for (; 1;) { //블록 움직임 반복

		if (kbhit()) { // 키입력 처리 ---------------------------------
			clearBlock();
			ch = getch();
			if (ch == 0xE0) { //방향키를 눌럿을 때×
				ch = getch();
				switch (ch) {
				case LEFT:
					x--;
					break;
				case RIGHT:
					x++;
					break;
				case DOWN:
					y++;
					break;
				case UP:
					sh++;
					if (sh > 3) sh = 0;
					break;
				}
			}
			printBlock();
		} // ------------------- 키입력 처리 종료
		Sleep(100); /* 0.1초간 대기 */
	}
}

void printMap() /* 맵 그리기 */
{
	int i, j;

	for (i = 0; i < Xsize; i++) /* 맨 윗줄U */
		printf("■");
	printf("\n");

	for (i = 0; i < Ysize - 2; i++) { /* 중간 */
		for (j = 0; j < Xsize; j++)
		if (j == 0 || j == Xsize - 1) printf("■"); /* 처음과 끝에 만 검은 사각형 */
		else printf("  "); /* 가운데는 공백 */
		printf("\n");
	}

	for (i = 0; i < Xsize; i++) /* 맨 아랫줄  */
		printf("■");
	printf("\n");
}
void clearBlock() //블록의 모양을 지움
{
	for (int i = 0; i < 4; i++) { //해당 좌표에 있는 블록의 위치를 삭제
		gotoxy(y + block[sh][i].y, (x + block[sh][i].x) * 2); /* 현재 위치 + 블록 하나의 위치를 더한 위치에 출력 */
		printf("  ");
	}
}

void printBlock() //블록의 모양을 출력
{
	for (int i = 0; i < 4; i++) { //해당 좌표에 있는 블록의 위치를 출력
		gotoxy(y + block[sh][i].y, (x + block[sh][i].x) * 2);
		printf("■");
	}
}

void gotoxy(int x, int y) //해당 위치를 찾아감
{
	COORD Pos = { y, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void noCursor() // 커서를 없앤다
{
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
