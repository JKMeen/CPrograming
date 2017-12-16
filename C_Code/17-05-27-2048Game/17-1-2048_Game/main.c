#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//�Է�Ű�� �ƽ�Ű�ڵ� ����
#define LEFT 75			// ���� ����Ű
#define RIGHT 77		// ������ ����Ű
#define UP 72			// ���� ����Ű
#define DOWN 80			// �Ʒ��� ����Ű
#define SPACEBAR 32		// �����̽���

// ���� ũ��
#define Xsize 5
#define Ysize 5
#define Max_Size 4

struct point{
	int x, y;		// ���� ��ǥ
	int number;		// ���� ����
	int select;		// �� ���� on / off
};

// ���ӿ����� ���� ��
struct point object[Max_Size][Max_Size];	// ��ü ������Ʈ


// global ����
int x = 1, y = 1;			// x, y��ǥ
int select_x = 1, select_y = 1; // ���� x, y ��ǥ
int select_on = -1;			// �ش� ��ǥ�� ������Ʈ ���� (space�ٸ� ������ Ȱ��ȭ)


// �Լ�
void Setting_Object();		// ������Ʈ �ʱ� ����
void Select_Object();		// ������Ʈ ���� �Լ�
void Draw_Object();			// ������Ʈ �׸��� �Լ�
void Clear_Object();		// ������Ʈ ����� �Լ�

void Draw_Map();			// �� �׸��� �Լ�

void PosXY(int x, int y);	// ��ġ ã�� �Լ�
void Hide_Cursor();			// Ŀ�� ���� �Լ�
void Keyboard_Check();		// Ű���� üũ �Լ�


// ���� �Լ�
void main(){
	Setting_Object();		// ������Ʈ ���� ����
	Draw_Map();				// �� �׸���
	//Draw_Object();			// ������Ʈ �׸���

	// ��� ������ �ݺ�
	for (; 1;){
		Keyboard_Check();	// Ű���� üũ �� �ٽ� �׷���
	}
}

// Ű���� üũ �Լ�
void Keyboard_Check(){
	if (_kbhit()){
		int key = _getch();
		Clear_Object();
		if (key == 0xE0) { // ����Ű
			key = _getch();
			switch (key){
			case LEFT:	if (x > 3)				x -= 3; break;	// ���� ����Ű
			case RIGHT: if (x < (Xsize - 2) * 3)	x += 3; break;	// ������ ����Ű
			case UP:	if (y > 1)				y--; break;	// ���� ����Ű
			case DOWN:	if (y < Ysize - 1)		y++; break;	// �Ʒ��� ����Ű
			}
			Draw_Object(x, y);
		}
		else { // Ư�� Ű
			switch (key){
			case SPACEBAR:							// ����, �����̽���
				// ó�� ���� ���� (����)
				if (select_on == -1){
					select_on = 1;
					select_x = x;
					select_y = y;
					object[y - 1][x / 3].select = 1;
					Draw_Object(x, y);
					Draw_Object(select_x, select_y);
				}

				// ���� ���� - �ٸ� ������Ʈ ���� (���� ���� / ���� ��ħ)
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

// ó�� ������Ʈ ����
void Setting_Object(){
	srand((unsigned)time(NULL)); // ���� ����

	// �ʱ� ���� ����
	for (int i = 0; i < Max_Size; i++){
		for (int j = 0; j < Max_Size; j++){
			// ��ġ ����
			object[i][j].x = j;
			object[i][j].y = i;

			object[i][j].select = 0;

			// ���� ����
			object[i][j].number = 2;
			float random = rand() % 2 + 1;
			for (int k = 1; k < random; k++){
				object[i][j].number *= 2;
			}
		}
	}
}

// ��ü �� �׸���
void Draw_Map(){
	// �� ��� ��
	for (int i = 0; i <= Xsize; i++){
		printf("��");
	} printf("�̢�\n");

	// �߰� ��
	for (int i = 1; i < Ysize; i++){
		for (int j = 0; j <= Xsize; j++){
			if (j == 0) printf("��");	// ù��° ���� ������ ���� �׷���
			else if (j == Xsize) printf("��");
			else {
				printf(" %d ", object[i - 1][j - 1].number);
			}
		}
		printf("\n");
	}

	// ������ ��
	for (int i = 0; i <= Xsize; i++){
		printf("��");
	} printf("�̢�\n");


	// 2048 game
	for (int i = 0; i <= Xsize; i++){
		printf("**");
	} printf("****\n");
	printf("�� 2048  GAME �� \n");
	for (int i = 0; i <= Xsize; i++){
		printf("��");
	} printf("�̢�\n");
}


// ������Ʈ �׸���
void Draw_Object(int x, int y){
	PosXY(y, x + 2);
	if (select_on == -1 && object[y - 1][x / 3].select == 1)
		printf(" %d ", object[y - 1][x / 3].number);
	else if (select_on == 1 && object[y - 1][x / 3].select == 1)
		printf("%d)", object[y - 1][x / 3].number);
}


// ������Ʈ �����
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

// ��ġ ã��
void PosXY(int x, int y){
	COORD Pos = { y, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}