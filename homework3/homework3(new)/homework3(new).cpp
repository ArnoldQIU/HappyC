#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Fib(int n);//�ŧi�O�B�Ǧ���
int main(void) {
	int number,result,num0,num1,num2;
	clock_t Start, End; //�ŧi�ɶ��ܼ�
	printf("%s", "��J�@�Ӿ�ƭp��]�@�ʸU���ɶ�:");
	scanf("%d", &number);
	// �ϥλ��j�p��Fib�ƭ�
	printf("%d\n", Fib(number));
	Start = clock();//�}�l�p�⻼�j�{���ɶ�
	for (int i = 1; i <= 1000000; i++) {
		Fib(number);
	}
	End = clock();//���j�{�������ɶ�
	printf("���j:%f   ", double(End - Start) / CLOCKS_PER_SEC);//�L�X���j�{���ɶ�
	
	Start = clock();//�p��D���j�{���ɶ�
	for (int i = 1; i <= 1000000; i++) {
		num0 = 1;//������l��
		num1 = 2;
		num2 = 2;
		for (int k = 1; k <= number;k++){    //�D���j�{��
			result = 2 * num2 + num1 - num0; //�O�B�Ǧ�
			num0 = num1;  
			num1 = num2;
			num2 = result;
		}
	}
	End = clock();//�����D���j�ɶ�
	printf("�D���j:%f\n", double(End-Start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}


int Fib( int n) { //�O�B�Ǧ���
	// base case
	if (n==0) {return 1;}
	if (n == 1 || n == 2) { return 2; }
	else {
		return 2*Fib(n - 1) + Fib(n - 2)-Fib(n-3);
	}
}