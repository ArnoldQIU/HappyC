#include"Header.h"

 
void decode(char *input, char *output) {

	int lens = -1;
	for (int a = 0; input[a - 1] != '\0'; a++) {			//�p���ɮפ�URL����
		lens++;
	}

	int locate = 0;													//output���r����m

	if (input[lens - 1] != '\n') {								//�̫�@�y�Y�L����Ÿ��A��+1(��<times ���F���L����Ÿ�)
		lens++;
	}

	for (int i = 1; i < lens; i++) {  //<���F���L����Ÿ�

		if ((input[i - 1] == '%') && (isxdigit(input[i])) && (isxdigit(input[i + 1]))) {	//����%��O�_���G�ӤQ���i��A�O�h��
			char ans = decimal(input[i], input[i + 1]);
			i += 2;
			output[locate] = ans;
			locate++;
		}
		else {
			output[locate] = input[i - 1];
			locate++;
		}
	}
	output[locate] = '\0';												//�r���ɤW�����r��
	puts(output);
}

char decimal(char first, char last) {     //10�줸�s�X
	char base16[] = "0123456789ABCDEF";
	int seg = 0;
	int ans;
	while (first != base16[seg]) {
		seg++;
	}
	ans = seg * 16;                    //16�i����^��10�i�� 
	seg = 0;
	while (last != base16[seg]) {
		seg++;
	}
	ans = ans + seg;
	return ans;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//


int main(int argc, char *argv[]) { //argc �Ѽ��`�� argv[] �ѼƦ�}
	if (argc > 1) {
		if (strcmp(argv[1], "e") == 0 && argc == 4) {    //strcmp(a,b) ���a,b�O�_�۵�
			enorde(argv[2], argv[3], 'e');
			printf("�ɮצ���\n");
		}
		else if (strcmp(argv[1], "d") == 0 && argc == 4) {
			enorde(argv[2], argv[3], 'd');
			puts("");
			printf("�ɮצ���\n");
		}
		else {
			printf("�ɮצ��� \n");
		}
	}
	
	return 0;
	system("pause");
}