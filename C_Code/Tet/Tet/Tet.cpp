#include "Tet.h"

#include <stdio.h>                     //��Ʈ���� �����//
 #include <windows.h>
 #include <conio.h>

#define LEFT 75 //�Է�Ű�� �ƽ�Ű�ڵ� ����
#define RIGHT 77
#define UP 72
#define DOWN 80

#define Xsize 20 /* ���� ũ�� */
 #define Ysize 26

struct point { //�� ��� ��ü�� ��ǥ
 int x, y;
 };

//���ӿ��� ���Ǵ� ����� ���� [����][���� ��ǥ]
point block[4][4] = { -1,0,0,0,1,0,0,-1, -1,0,0,-1,0,0,0,1, -1,0,0,0,1,0,0,1, 0,-1,0,0,0,1,1,0 };

int x, y; //�迭�������� ��ǥ
int sh, n; //����� ������� �ѹ�

void clearBlock(); //��� ����
void printBlock(); //��� ���
void printMap(); /* �� �׸��� */
void gotoxy(int x, int y); //�ش���ġ�� ã�ư�
void noCursor(); //Ŀ���� ���ش�.

void main()
 {
  int ch;
  x=5; /*ó�� ��ǥ */
  y=2;
  noCursor(); /* Ŀ�� ���� */
  printMap(); /* �� �׸��� */
  printBlock(); /* ��� ��� */

 for (; 1 ;) { //��� ������ �ݺ�

  if ( kbhit() ) { // Ű�Է� ó�� ---------------------------------
   clearBlock();
    ch = getch();
    if (ch == 0xE0) { //����Ű�� ������ ����
    ch = getch();
     switch(ch) {
     case LEFT :
      x--;
      break;
     case RIGHT :
      x++;
      break;
     case DOWN :
      y++;
      break;
     case UP :
      sh++;
      if (sh > 3) sh = 0;
      break;
     }
    }
    printBlock();
   } // ------------------- Ű�Է� ó�� ����
  Sleep(100); /* 0.1�ʰ� ��� */
  }
 }

void printMap() /* �� �׸��� */
 {
  int i, j;

 for (i=0; i<Xsize; i++) /* �� ����U */
   printf("��");
  printf("\n");

 for (i=0; i<Ysize-2; i++) { /* �߰� */
   for (j=0; j<Xsize; j++)
    if (j == 0 || j == Xsize-1) printf("��"); /* ó���� ���� �� ���� �簢�� */
    else printf("  "); /* ����� ���� */
   printf("\n");
  }

 for (i=0; i<Xsize; i++) /* �� �Ʒ���  */
   printf("��");
  printf("\n");
 }
 void clearBlock() //����� ����� ����
{
  for (int i=0; i<4; i++) { //�ش� ��ǥ�� �ִ� ����� ��ġ�� ����
  gotoxy(y+block[sh][i].y, (x+block[sh][i].x)*2); /* ���� ��ġ + ��� �ϳ��� ��ġ�� ���� ��ġ�� ��� */
   printf("  ");
  }
 }

void printBlock() //����� ����� ���
{
  for (int i=0; i<4; i++) { //�ش� ��ǥ�� �ִ� ����� ��ġ�� ���
  gotoxy(y+block[sh][i].y, (x+block[sh][i].x)*2);
   printf("��");
  }
 }

void gotoxy(int x, int y) //�ش� ��ġ�� ã�ư�
{
  COORD Pos = {y, x};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
 }

void noCursor() // Ŀ���� ���ش�
 {
  CONSOLE_CURSOR_INFO CurInfo;
  CurInfo.dwSize=1;
  CurInfo.bVisible=FALSE;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
 }
