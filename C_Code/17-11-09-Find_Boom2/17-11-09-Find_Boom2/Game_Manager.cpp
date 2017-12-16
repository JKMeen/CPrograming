#include "Game_Manager.h"

// ������
GameManager::GameManager(){
	x = 1;
	y = 1;

	boom_x = 1;
	boom_y = 1;

	count = 0;
	clear = 0;

	// �ʱ� ����
	Initlized();
	Draw_Map();
}

// �Ҹ���
GameManager::~GameManager(){
	//delete point;
}

// ������Ʈ �ʱ� ����
void GameManager::Initlized(){				
	srand((unsigned)time(NULL)); // ���� ����

	// �ʱ� ���� ����
	for (int i = 0; i < Xsize; i++){
		for (int j = 0; j < Ysize; j++){
			// ���� �Ҵ�
			point[i][j] = (struct Object*)malloc(sizeof(struct Object));

			// ��ġ ����
			point[i][j]->x = j;
			point[i][j]->y = i;

			point[i][j]->select = 0;

			// ���� ����
			point[i][j]->find = 1;
			point[i][j]->number = '?';
		}
	}

	boom_y = rand() % Xsize;
	boom_x = rand() % Ysize;
	point[boom_y][boom_x]->find = 'B';
}

// ������Ʈ ���� �Լ�
void GameManager::Select_Object(){

}

// ������Ʈ �׸��� �Լ�
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
			cout << "��" << " ";
		}
		
	}
}

// ������Ʈ ����� �Լ�
void GameManager::Clear_Object(){
	PosXY(y, x + 3);

	for (int i = 0; i <= Xsize-1; i++){
		for (int j = 0; j < Ysize-1; j++){
			PosXY(j + 1, (i + 1) * 3);
			if (clear == 1){
				cout << " " << "��" << " ";
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

// �� �׸��� �Լ�
void GameManager::Draw_Map(){
	// �� ��� ��
	for (int i = 0; i <= (Xsize + 1) / 2; i++){
		cout << "��I";
	}
	for (int i = (Xsize + 1) / 2; i < Xsize + 1; i++){
		cout << "I��";
	} cout << endl;

	// �߰� ��
	for (int i = 1; i < Ysize; i++){
		for (int j = 0; j <= Xsize+1; j++){
			if (j == 0) 
				cout << "�� ";	// ù��° ���� ������ ���� �׷���
			else if (j == Xsize + 1){
				cout << " ��";	// ù��° ���� ������ ���� �׷���
			}
			else {
				cout << " " << point[j - 1][i]->number << " ";
			}
		}
		cout << endl;
	}

	// ������ ��
	for (int i = 0; i <= (Xsize + 1) / 2; i++){
		cout << "��I";
	}
	for (int i = (Xsize + 1) / 2; i < Xsize + 1; i++){
		cout << "I��";
	} cout << endl;


	// Print Find Boom Game
	for (int i = 0; i <= Xsize+1; i++){
		cout <<"***";
	} cout << endl;

	//
	for (int i = 0; i <= (Xsize + 1)/2; i++){
		cout << "��I";
	}
	for (int i = (Xsize + 1) / 2; i < Xsize + 1; i++){
		cout << "I��";
	} cout << endl;

	//
	for (int i = 0; i <= (Xsize + 1) / 3; i++)
		cout << "��I";

	cout << " <FIND BOOM GAME> ";

	for (int i = (Xsize + 1) / 3 * 2; i <= Xsize + 1; i++){
		cout << "I��";
	} cout << endl;


	//
	for (int i = 0; i <= (Xsize + 1) / 2; i++){
		cout << "��I";
	}
	for (int i = (Xsize + 1) / 2; i < Xsize + 1; i++){
		cout << "I��";
	} cout << endl;
}

// ��ġ ã�� �Լ�
void GameManager::PosXY(int x, int y){
	COORD Pos = { y, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// Ŀ�� ���� �Լ�
void GameManager::Hide_Cursor(){

}

// Ű���� üũ �Լ�
void GameManager::Keyboard_Check(){
	if (_kbhit()){
		int key = _getch();
		Clear_Object();
		
		if (key == 0xE0) { // ����Ű
			key = _getch();
			switch (key){
			case LEFT:	if (x > 3)				x -= 3; break;	// ���� ����Ű
			case RIGHT: if (x < (Xsize - 1) * 3)	x += 3; break;	// ������ ����Ű
			case UP:	if (y > 1)				y--; break;	// ���� ����Ű
			case DOWN:	if (y < Ysize - 1)		y++; break;	// �Ʒ��� ����Ű
			}
			Draw_Object(x, y);
		}
		else { // Ư�� Ű
			switch (key){
			case SPACEBAR:							// ����, �����̽���
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