#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define scanf scanf_s

void main(){
	srand((unsigned)time(NULL));

	int boom_x, boom_y;
	int x, y;
	char p[10][10];

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			p[i][j] = 'S';
		}
	}

	boom_x = rand() % 10;
	boom_y = rand() % 10;
	p[boom_x][boom_y] = 'B';
	printf("��ź :: %d, %d\n\n", boom_x, boom_y);

	while (true){
		printf("x, y ��ġ ��ǥ�� �Է����ּ���.[0~9, 0~9] >>> ");
		scanf("%d %d", &x, &y);

		if (x < 0 || x > 9 || y < 0 || y > 9){
			printf("�� �� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
		}
		else if (x != boom_x || y != boom_y){
			for (int i = 0; i < abs(boom_x-x) + abs(boom_y-y); i++){
				printf("��-");
			}
			printf("[%c] \n\n", p[x][y]);
		}
		else{
			printf("<��ź�� �����Ǿ����ϴ�.> [%c] \n", p[x][y]);
			break;
		}
	}
}