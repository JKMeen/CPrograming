#include <stdio.h>

#define scanf scanf_s

void main(){
	for (int i = 0; i < 100; i += 10){
		printf("È­¾¾¿Âµµ %3dµµ´Â ¼·¾¾·Î %3dÀÔ´Ï´Ù.\n", i, (i-32) * 5 / 9);
	}
}