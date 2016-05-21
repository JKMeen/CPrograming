//독학) 포인트. 주소값//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i=10;
	int *pi=&i;

	printf("i=%d, pi=%p\n", i, pi); // i=10, pi=00EAF8D8

	(*pi)++;
	printf("i=%d, pi=%p\n", i, pi); // i=11, pi=00EAF8D8 pi는 바뀌지 않았다.

	*pi++;
	printf("i=%d, pi=%p\n", i, pi); // i=11, pi=00EAF8DC pi도ì 같이 바뀌었다.

	return 0;
}