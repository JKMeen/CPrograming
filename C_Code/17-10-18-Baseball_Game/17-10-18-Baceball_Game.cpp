// ���� ���̽��� ����
// 3 1 2
// 1 3 2 =>	1s 2b
// 3 1 4 =>	2s

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void main(){
	// ��ǻ�Ͱ� ���� 3���� ���� �������� ������.
	// �ݺ������� ������� ���ڰ� ������ �� �� ���� �ݺ��Ѵ�
	// ���� Ʋ���� ���� ���� ���� �ڸ��� ���� ��Ʈ����ũ�� ���� �Ǻ��Ѵ�.
	// ������ ������ ���α׷� ����

	srand((unsigned)time(NULL));

	int com[3]; // a[0]~a[9]

	do{
		for(int i=0; i<3; i++){
			com[i] = (int)rand()% 10 + 1;		
		}		
	} while(com[0] == com[1] || com[1] == com[2] || com[2] == com[0]);

	// ��ǻ�� ����
	for(int i=0; i<3; i++){
		printf("[%d] ", com[i]);	
	}	
	printf("\n���� ����!\n");
	int strike = 0;		 // ��Ʈ����ũ ī��Ʈ
	int ball = 0;        // �� ī��Ʈ

	int pla[3];

	while(true){	// ���� �ݺ�
		printf("���� �� �� �Է� >>> ");
		for(int i=0; i<3; i++){				// 3�� �ݺ�
			scanf("%d", &pla[i]);	 	    // ����� ���ڸ� �Է� ����
		}

		// ����� ���ڰ� �´��� �˻�
		for (int i=0; i<3; i++){				   // for�� 3�� �ݺ�
			for (int j=0; j<3; j++){			   // ���� for�� 3�� �ݺ�
				 // �ڸ��� ���� ���
				if (i == j){					   
					if (com[i] == pla[j]){
						strike++;
					}
				} 	  // i = 2   // j = 2
				
				// �ڸ��� �ٸ� ���
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
	
	printf("�� ���\n");
}


