/*
利用泰勒展式近似求cos(x)的值
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	printf("COSx 泰勒展開式:= 1 - x^2/2! + x^4/4! - x^6/6! + x^8/8! - x^10/10! + ...... \n");
	int x, i;
	float F, s, p, sum, cos;
	printf("請輸入x:");
	scanf("%d",&x);
	printf("\n請輸入i:");
	scanf("%d",&i);
	sum = 1;
	for (F = 2; F <= 20; F++){
		p = 1;
		if (F == 1)  //在零階的時候為1
		{
			F = 1.5;}
		for (s = 1; s <= (F- 1) * 2; s++)//計算分母的階層
		{p *= s;
		}
		cos = pow(-1, (F - 1)) * pow(x, 2 * (F- 1)) / p; //泰勒展開式
		
		sum+=cos;//級數相加

		if (fabs(cos) < pow(10, -1 * i)) //滿足 | cos x(j) − cos x(j−1) | < 10**(-i)
		{
			printf("\n第一題答案:%.0f\n", F);
			break;}
	}
	printf("\n第二題答案:%.5f\n", sum);
	system("pause");
}

