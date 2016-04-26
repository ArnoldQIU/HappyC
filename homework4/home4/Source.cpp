#include<stdio.h>
#include<stdlib.h>
#define p printf         //printf簡寫 減少打字時間
int m, n;				//宣告全域變數
int *num;				//指標變數
void perm(int a,int b); //導入函式
int re(void);

int main(void) {         //主程式
	p("輸入一個數字n:");           //基本資料輸入								
	scanf("%d", &n);               
	p("輸入一個數字m:");          
	scanf("%d", &m);                     
	while (m > n || m < 0) {
		p("輸入錯誤請重新輸入\n");
		p("輸入一個數字n:\n");
		scanf("%d", n);
		p("輸入一個數字m:\n");
		scanf("%d", m);
	}
	num = new int[m];  //分配記憶體位址 (陣列)
	perm(n, 1);			//函式計算
	system("pause");
}

int re(void) {										//檢查有無重複
	for (int m1 = 1; m1 <= m; m1++) {               //有陣列相同傳回true,無則false
		for (int m2 = m1 + 1; m2 <= m; m2++) {      
			if (num[m1] == num[m2]) {
				return true;
			}
		}
	}
	return false;
}
void perm(int a, int b) {
	for (num[b] = 1; num[b] <= a; num[b]++) {
		if (b > m) {
			return;
		}
		else {
			perm(a - 1, b + 1);
		}
		if (re() == false) {                      //無重複印出
			for (int i = 1; i <= m; i++) {
				p("%d ", num[i]);
			}
			p("\n");
		}
	}

}