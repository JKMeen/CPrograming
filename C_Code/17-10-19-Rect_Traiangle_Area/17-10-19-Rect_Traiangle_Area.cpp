#include <stdio.h>
#include <math.h>

#define scanf scanf_s

void main(){
	int hight = 10;

	for (int i = 10; i <= 20; i += 2){
		printf("사각형의   높이 : %3d cm\n", hight);
		printf("사각형의   밑변 : %3d cm\n", i);
		printf("사각형의   면적 : %3d cm²\n", i*hight);

		printf("삼각형의   높이 : %3d cm\n", hight);
		printf("삼각형의   밑변 : %3d cm\n", i);
		printf("삼각형의 대각변 : %2.2f cm\n", sqrtf(((i / 2)*(i / 2)) + (hight*hight)));
		printf("삼각형의   면적 : %3d cm²\n\n", i*hight / 2);
	}
}