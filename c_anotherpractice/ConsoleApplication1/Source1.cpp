#include<stdio.h>
#include<stdlib.h>
void replace(int &n1, int &n2);
void main(void) {
	int arr1[7] = { 10,-5,6,54,-42,12,35 };
	printf("¸m´««e°}¦C");
	for (int a = 1; a <= 7; a++) {
		printf("%d ", arr1[a - 1]);
	}
	puts("");
	for (int i = 1; i <= 7; i++) {
			if (arr1[i - 1] < 0) {
				for (int j = i+1; j <= 7; j++) {
					if (arr1[j - 1] < 0) {
						replace(arr1[i - 1], arr1[j - 1]);
					}
				}
			}
		}
	printf("¸m´««á°}¦C");
	for (int a = 1; a <= 7; a++) {
		printf("%d ", arr1[a - 1]);
	}
	puts("");
	system("pause");
}
void replace(int &n1, int &n2) {
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}