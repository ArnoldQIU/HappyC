#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Fib(int n);//宣告費伯納西函數
int main(void) {
	int number,result,num0,num1,num2;
	clock_t Start, End; //宣告時間變數
	printf("%s", "輸入一個整數計算跑一百萬次時間:");
	scanf("%d", &number);
	// 使用遞迴計算Fib數值
	printf("%d\n", Fib(number));
	Start = clock();//開始計算遞迴程式時間
	for (int i = 1; i <= 1000000; i++) {
		Fib(number);
	}
	End = clock();//遞迴程式結束時間
	printf("遞迴:%f   ", double(End - Start) / CLOCKS_PER_SEC);//印出遞迴程式時間
	
	Start = clock();//計算非遞迴程式時間
	for (int i = 1; i <= 1000000; i++) {
		num0 = 1;//給予初始值
		num1 = 2;
		num2 = 2;
		for (int k = 1; k <= number;k++){    //非遞迴程式
			result = 2 * num2 + num1 - num0; //費伯納西
			num0 = num1;  
			num1 = num2;
			num2 = result;
		}
	}
	End = clock();//結束非遞迴時間
	printf("非遞迴:%f\n", double(End-Start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}


int Fib( int n) { //費伯納西函數
	// base case
	if (n==0) {return 1;}
	if (n == 1 || n == 2) { return 2; }
	else {
		return 2*Fib(n - 1) + Fib(n - 2)-Fib(n-3);
	}
}