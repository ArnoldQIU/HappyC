#include<stdio.h>
#include<stdlib.h>
#define p printf         //printf²�g ��֥��r�ɶ�
int m, n;				//�ŧi�����ܼ�
int *num;				//�����ܼ�
void perm(int a,int b); //�ɤJ�禡
int re(void);

int main(void) {         //�D�{��
	p("��J�@�ӼƦrn:");           //�򥻸�ƿ�J								
	scanf("%d", &n);               
	p("��J�@�ӼƦrm:");          
	scanf("%d", &m);                     
	while (m > n || m < 0) {
		p("��J���~�Э��s��J\n");
		p("��J�@�ӼƦrn:\n");
		scanf("%d", n);
		p("��J�@�ӼƦrm:\n");
		scanf("%d", m);
	}
	num = new int[m];  //���t�O�����} (�}�C)
	perm(n, 1);			//�禡�p��
	system("pause");
}

int re(void) {										//�ˬd���L����
	for (int m1 = 1; m1 <= m; m1++) {               //���}�C�ۦP�Ǧ^true,�L�hfalse
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
		if (re() == false) {                      //�L���ƦL�X
			for (int i = 1; i <= m; i++) {
				p("%d ", num[i]);
			}
			p("\n");
		}
	}

}