// 숫자 베이스볼 게임
// 3 1 2
// 1 3 2 =>	1s 2b
// 3 1 4 =>	2s

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void main(){
	// 컴퓨터가 숫자 3개를 먼저 랜덤으로 돌린다.
	// 반복문으로 사용자의 숫자가 정답이 될 때 까지 반복한다
	// 만약 틀리면 같은 수와 같은 자리를 보고 스트라이크와 볼로 판별한다.
	// 정답이 맞으면 프로그램 종료

	srand((unsigned)time(NULL));

	int com[3]; // a[0]~a[9]

	do{
		for(int i=0; i<3; i++){
			com[i] = (int)rand()% 10 + 1;		
		}		
	} while(com[0] == com[1] || com[1] == com[2] || com[2] == com[0]);

	// 컴퓨터 숫자
	for(int i=0; i<3; i++){
		printf("[%d] ", com[i]);	
	}	
	printf("\n게임 시작!\n");
	int strike = 0;		 // 스트라이크 카운트
	int ball = 0;        // 볼 카운트

	int pla[3];

	while(true){	// 무한 반복
		printf("숫자 세 개 입력 >>> ");
		for(int i=0; i<3; i++){				// 3번 반복
			scanf("%d", &pla[i]);	 	    // 사용자 숫자를 입력 받음
		}

		// 사용자 숫자가 맞는지 검사
		for (int i=0; i<3; i++){				   // for문 3번 반복
			for (int j=0; j<3; j++){			   // 이중 for문 3번 반복
				 // 자리가 같을 경우
				if (i == j){					   
					if (com[i] == pla[j]){
						strike++;
					}
				} 	  // i = 2   // j = 2
				
				// 자리가 다를 경우
				else {							
					if (com[i] == pla[j]){
						ball++;
					}
				}
			}
		}

		printf("strike :: %d , ball :: %d\n", strike, ball);

		if (strike == 3)
			break;
		else {
			strike = 0;
			ball = 0;
		}
	}
	
	printf("와 대박\n");
}


