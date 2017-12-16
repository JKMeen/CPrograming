#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

//�Է�Ű�� �ƽ�Ű�ڵ� ����
#define LEFT 75			// ���� ����Ű
#define RIGHT 77		// ������ ����Ű
#define UP 72			// ���� ����Ű
#define DOWN 80			// �Ʒ��� ����Ű
#define SPACEBAR 32		// �����̽���
#define ESCAPE 33		// Escape

// ���� ũ��
#define Xsize 20
#define Ysize 20
#define Max_Size 4

struct Object{
	int x, y;		// ���� ��ǥ
	int select;		// �� ���� on / off
	char number;	// ���� ��Ȳ
	int find;		// ������ ���� ��Ȳ
};

class GameManager{
public:
	GameManager();
	~GameManager();

	void Initlized();				// ������Ʈ �ʱ� ����
	void Select_Object();				// ������Ʈ ���� �Լ�
	void Draw_Object(int x, int y);		// ������Ʈ �׸��� �Լ�
	void Clear_Object();				// ������Ʈ ����� �Լ�

	void Draw_Map();					// �� �׸��� �Լ�

	void PosXY(int x, int y);			// ��ġ ã�� �Լ�
	void Hide_Cursor();					// Ŀ�� ���� �Լ�
	void Keyboard_Check();				// Ű���� üũ �Լ�

	Object *point[Xsize][Ysize];
	int count;
	int clear;
	int x, y;
	int boom_x, boom_y;
};