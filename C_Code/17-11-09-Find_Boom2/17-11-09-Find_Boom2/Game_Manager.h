#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

//입력키의 아스키코드 저장
#define LEFT 75			// 왼쪽 방향키
#define RIGHT 77		// 오른쪽 방향키
#define UP 72			// 위쪽 방향키
#define DOWN 80			// 아래쪽 방향키
#define SPACEBAR 32		// 스페이스바
#define ESCAPE 33		// Escape

// 맵의 크기
#define Xsize 20
#define Ysize 20
#define Max_Size 4

struct Object{
	int x, y;		// 점의 좌표
	int select;		// 점 선택 on / off
	char number;	// 점의 상황
	int find;		// 선택한 점의 상황
};

class GameManager{
public:
	GameManager();
	~GameManager();

	void Initlized();				// 오브젝트 초기 설정
	void Select_Object();				// 오브젝트 선택 함수
	void Draw_Object(int x, int y);		// 오브젝트 그리기 함수
	void Clear_Object();				// 오브젝트 지우기 함수

	void Draw_Map();					// 맵 그리기 함수

	void PosXY(int x, int y);			// 위치 찾기 함수
	void Hide_Cursor();					// 커서 삭제 함수
	void Keyboard_Check();				// 키보드 체크 함수

	Object *point[Xsize][Ysize];
	int count;
	int clear;
	int x, y;
	int boom_x, boom_y;
};