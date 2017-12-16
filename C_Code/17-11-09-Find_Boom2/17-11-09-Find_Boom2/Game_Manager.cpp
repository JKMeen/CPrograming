#include "Game_Manager.h"

// 생성자
GameManager::GameManager(){
	x = 1;
	y = 1;

	boom_x = 1;
	boom_y = 1;

	count = 0;
	clear = 0;

	// 초기 지정
	Initlized();
	Draw_Map();
}

// 소멸자
GameManager::~GameManager(){
	//delete point;
}

// 오브젝트 초기 설정
void GameManager::Initlized(){				
	srand((unsigned)time(NULL)); // 랜덤 설정

	// 초기 숫자 지정
	for (int i = 0; i < Xsize; i++){
		for (int j = 0; j < Ysize; j++){
			// 동적 할당
			point[i][j] = (struct Object*)malloc(sizeof(struct Object));

			// 위치 지정
			point[i][j]->x = j;
			point[i][j]->y = i;

			point[i][j]->select = 0;

			// 숫자 지정
			point[i][j]->find = 1;
			point[i][j]->number = '?';
		}
	}

	boom_y = rand() % Xsize;
	boom_x = rand() % Ysize;
	point[boom_y][boom_x]->find = 'B';
}

// 오브젝트 선택 함수
void GameManager::Select_Object(){

}

// 오브젝트 그리기 함수
void GameManager::Draw_Object(int x, int y){
	PosXY(y, x + 3);

	if (point[y - 1][(x - 1) / 3]->select == 0)
		cout << point[y - 1][(x - 1) / 3]->number << " ";
	else if (point[y - 1][(x - 1) / 3]->select == 1){
		if (boom_y != (y - 1) || boom_x != ((x - 1) / 3)){
			point[y - 1][(x - 1) / 3]->find = abs(boom_y - (y - 1)) + abs(boom_x - ((x - 1) / 3));
			cout << point[y - 1][(x - 1) / 3]->find << " ";
		}
		else {
			cout << "□" << " ";
		}
		
	}
}

// 오브젝트 지우기 함수
void GameManager::Clear_Object(){
	PosXY(y, x + 3);

	for (int i = 0; i <= Xsize-1; i++){
		for (int j = 0; j < Ysize-1; j++){
			PosXY(j + 1, (i + 1) * 3);
			if (clear == 1){
				cout << " " << "□" << " ";
			}
			else {
				if (point[j][i]->select == 0)
					cout << " " << point[j][i]->number << " ";
				else if (point[j][i]->select == 1){
					cout << " " << point[j][i]->find << " ";
				}
			}
		}
	}
}

// 맵 그리기 함수
void GameManager::Draw_Map(){
	// 최 상단 줄
	for (int i = 0; i <= (Xsize + 1) / 2; i++){
		cout << "▩I";
	}
	for (int i = (Xsize + 1) / 2; i < Xsize + 1; i++){
		cout << "I▩";
	} cout << endl;

	// 중간 줄
	for (int i = 1; i < Ysize; i++){
		for (int j = 0; j <= Xsize+1; j++){
			if (j == 0) 
				cout << "▩ ";	// 첫번째 열과 마지막 열만 그려줌
			else if (j == Xsize + 1){
				cout << " ▩";	// 첫번째 열과 마지막 열만 그려줌
			}
			else {
				cout << " " << point[j - 1][i]->number << " ";
			}
		}
		cout << endl;
	}

	// 마지막 줄
	for (int i = 0; i <= (Xsize + 1) / 2; i++){
		cout << "▩I";
	}
	for (int i = (Xsize + 1) / 2; i < Xsize + 1; i++){
		cout << "I▩";
	} cout << endl;


	// Print Find Boom Game
	for (int i = 0; i <= Xsize+1; i++){
		cout <<"***";
	} cout << endl;

	//
	for (int i = 0; i <= (Xsize + 1)/2; i++){
		cout << "▩I";
	}
	for (int i = (Xsize + 1) / 2; i < Xsize + 1; i++){
		cout << "I▩";
	} cout << endl;

	//
	for (int i = 0; i <= (Xsize + 1) / 3; i++)
		cout << "▩I";

	cout << " <FIND BOOM GAME> ";

	for (int i = (Xsize + 1) / 3 * 2; i <= Xsize + 1; i++){
		cout << "I▩";
	} cout << endl;


	//
	for (int i = 0; i <= (Xsize + 1) / 2; i++){
		cout << "▩I";
	}
	for (int i = (Xsize + 1) / 2; i < Xsize + 1; i++){
		cout << "I▩";
	} cout << endl;
}

// 위치 찾기 함수
void GameManager::PosXY(int x, int y){
	COORD Pos = { y, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 커서 삭제 함수
void GameManager::Hide_Cursor(){

}

// 키보드 체크 함수
void GameManager::Keyboard_Check(){
	if (_kbhit()){
		int key = _getch();
		Clear_Object();
		
		if (key == 0xE0) { // 방향키
			key = _getch();
			switch (key){
			case LEFT:	if (x > 3)				x -= 3; break;	// 왼쪽 방향키
			case RIGHT: if (x < (Xsize - 1) * 3)	x += 3; break;	// 오른쪽 방향키
			case UP:	if (y > 1)				y--; break;	// 위쪽 방향키
			case DOWN:	if (y < Ysize - 1)		y++; break;	// 아래쪽 방향키
			}
			Draw_Object(x, y);
		}
		else { // 특수 키
			switch (key){
			case SPACEBAR:							// 선택, 스페이스바
				count++;
				point[y - 1][(x - 1)/3]->select = 1;
				if (boom_y == (y - 1) && boom_x == ((x - 1) / 3)){
					clear = 1;
					Clear_Object();
				}
				Draw_Object(x, y);
				
				break;
				
			case ESCAPE:
				exit(true);
				break;
			}
			
		}
	}
}