#include <stdio.h>
#include <Time.h>

int sec, mi, ho, Aho=1000, Ami=60;

void Get_Time(){
	printf("(시)(분)(초) 차례로 입력 : ");
	scanf_s("%d %d %d", &ho, &mi, &sec);
}

void Set_Time(){
	int msec = 0, ssec = 0;

	while (1)
	{
		ssec++;
		if (ssec == 100){
			msec++;
			ssec = 0;
			if (msec == 60){
				sec++;
				msec = 0;
				if (sec == 60) {
					mi++;
					sec = 0;
					if (mi == 60){
						ho++;
						mi = 0;
					}
				}
			}
		}
		printf_s("%d시 %d분 %d초 %dmsec %dssec\n", ho, mi, sec, msec, ssec);
		if (ho == Aho) { 
			if (mi = Ami){
				printf_s("\a\a\a\a\a\a\a\a\a 알람!!!!!");
				break;
			}
		}
	}
}

void Stopwatch(){
	int num;
	int ssec = 99, msec = 99, sec = 59, mi = 59;

	printf_s("분 입력 : ");
	scanf_s("%d", &num);

	mi = num-1;

	while (1)
	{
		for (ssec; ssec >= 0; ssec--)
		{
			if (ssec == 0){
				msec--;
				ssec = 100;
				if (msec == 0){
					sec--;
					msec = 60;
					if (sec == 0) {
						mi--;
						 sec = 60;
						if (mi <= 0) break;
					}
				}
			}
			printf_s("%d분 %d초 %dmsec %dssec\n", mi, sec, msec, ssec);
		}
		if (mi < 0) break;
	}
}

void Aram(){
	printf_s("알람시간 입력(시)(분) : ");
	scanf_s("%d %d", &Aho, &Ami);
}

void Reset(){
	sec=0, mi=0, ho=0, Aho=0, Ami=0;
}

void main()
{
	int ch;
	while (1){

		printf_s("기능 선택 (1)시간설정 (2)시간 (3)스탑워치 (4)리셋\n");
		scanf_s("%d", &ch);
		switch (ch)
		{
			case 1: Get_Time(); break;
			case 2: Set_Time(); break; 
			case 3: Stopwatch(); break;
			case 4: Aram(); break;
			case 5: Reset(); break;
		}
	}
}