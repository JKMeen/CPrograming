//독학) 배열/ 50가지의 랜덤 숫자의 합, 평균, 최대값, 최소값 구하기//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, j;
	int tmp;
	int sum, max, min;
	double avg;
	int num[50];

	srand(time(NULL)); // 시간에 따라 난수가 바뀐다.

	for(i=0;i<50;i++)
		num[i]=rand()%101;  // num[i]에 101가지의 숫자 중 하나를 넣는다.
                                             // (0~100까지 숫자임)
	i=0;                 // i를 0으로 초기화 한다. [중첩 방지]
	while(i<50)           
	{
	for(j=0;j<5;j++)          //j가 5까지 1씩 증가하는 동안
	{
	printf("%5d", num[i]);    // 5뭉터기의 정수 num[i]를 출력한다
	i++;                    // I는 1씩 증가한다.
	}
	printf("\n");
	}

	for(i=0; i<50; i++)      
	{
		for(j=(i+1);j<50;j++)       // j가 50까지 1씩 증가한다. j초기값 I+1
		{
			if(num[i]>num[j])  
			{
				tmp=num[i];     
				num[i]=num[j];   
				num[j]=tmp;     // 스왑(최대값과 최소값을 지정해줌)
			}                   //(이걸 빼면 랜덤의 숫자가 나옴)
		}                       
	}

	sum=0;           
	for(i=0;i<50;i++)        
		sum+=num[i]; // sum은 sum+num[i]값을 가진다.(50개의 숫자를 다 더한다)

	max=num[49]; 
	min=num[0];
	avg=sum/50.0;

	printf("전체 합 : %d\n", sum);
	printf("전체 평균 : %.2lf\n", avg);
	printf("최대값 : %d\n", max);
	printf("최소값 : %d\n", min);

	return 0;
}