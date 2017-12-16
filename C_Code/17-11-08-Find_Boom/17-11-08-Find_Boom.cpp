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
	printf("폭탄 :: %d, %d\n\n", boom_x, boom_y);

	while (true){
		printf("x, y 위치 좌표를 입력해주세요.[0~9, 0~9] >>> ");
		scanf("%d %d", &x, &y);

		if (x < 0 || x > 9 || y < 0 || y > 9){
			printf("잘 못 입력하셨습니다. 다시 입력해주세요.\n\n");
		}
		else if (x != boom_x || y != boom_y){
			for (int i = 0; i < abs(boom_x-x) + abs(boom_y-y); i++){
				printf("삑-");
			}
			printf("[%c] \n\n", p[x][y]);
		}
		else{
			printf("<폭탄이 해제되었습니다.> [%c] \n", p[x][y]);
			break;
		}
	}
}