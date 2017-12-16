#include <stdio.h>

double get_double();   // �Լ� ���� ����
double add(double x, double y);
double get_max(double x, double y);
void print_star();

void main(){
	double num1, num2;

    num1 = get_double();
	num2 = get_double();
	
	print_star();
	printf("�� �Ǽ��� �� : %.2f \n", add(num1, num2));
	printf("�� �Ǽ� �� ū �� : %.2f \n", get_max(num1, num2));
	print_star();
}

double add( double x, double y){
	return x+y;
}

double get_double(){
	double num;
	printf("�Ǽ� �ΰ� �Է� : ");
	scanf("%lf", &num);
	return num;
}

double get_max(double x, double y){
	if(x>y) return x;
	else return y;
}

void print_star(){
	int i;
	for(i=0; i<30; i++)
		printf("*");
	printf("\n");
}