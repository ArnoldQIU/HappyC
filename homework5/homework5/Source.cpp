
#include"Header.h"



void encode(char *enter, char *output) {

	int lens=-1;                                          
	for (int a = 0; enter[a - 1] != '\0'; a++) {			//�p���ɮפ�URL����
		lens++;
	}                                              

	if (enter[lens - 1] != '\n') {								//�̫�@�y�Y�L����Ÿ��A��+1(��<times ���F���L����Ÿ�)
		lens++;
	}
	
	
	int locate = 0;											    //output���r����m
	for (int i = 1; i < lens; i++) {

		if (!(isalnum(enter[i-1]) || (enter[i - 1] == '.'))) {	//isalnum �P�_�ϧ_���^��μƦr
			output[locate] = '%';
			locate++;
			output[locate] = hexadecimal(enter[i - 1], 1);//16�i��Ĥ@�Ӽ�
			locate++;
			output[locate] = hexadecimal(enter[i - 1], 2);//�ĤG�Ӽ�
			locate++;
		}
		else {
			output[locate] = enter[i - 1];
			locate++;
		}
	}
	output[locate] = '\0';												//�r���ɤW�����r��
	puts(output);
}

char hexadecimal(int asc, int locate) {            //16�줸�s�X
	char base16[] = "0123456789ABCDEF";
	if (locate == 1) {                        //�Ĥ@�ӼƦr�� 10�i��X/16 ���Ƴ���
		return base16[asc / 16];
	}
	else {
		return base16[asc % 16];			//�ĤG�ӼƦr 10�i��X/16 �l�Ƴ���
	}
}


void write(FILE *fPtr, char content[]) {
	for (int index = 0; content[index] != '\0'; index++) {
		fputc(content[index], fPtr);           //fputc() �q�N�r���@�Ӥ@�Ӫ�����ɮפ�
	}
	fputc('\n', fPtr);
}

FILE* open(char fileName[], char type[]) {
	FILE *fPtr = fopen(fileName, type);
	if (fPtr == NULL) {
		printf("The file opened error.\n");
		exit(1);
	}
	return fPtr;
}
void enorde(char source[], char destination[], char argv) {
	char result[1024];
	char input[256];
	FILE *sourcePtr = open(source, "r");
	FILE *desPtr = open(destination, "w");
	if (argv == 'e') {

		while (fgets(input, 256, sourcePtr) != NULL) {        //fgets(��J��ƪ��}�C,�Ӧ�̦h�X�Ӧr��,�ɮ׫���)�q�ɮ�Ū�����
			encode(input, result);
			write(desPtr, result);
		}

		fclose(sourcePtr);
		fclose(desPtr);
	}
	else {
		

		while (fgets(input, 256, sourcePtr) != NULL) {
			decode(input, result);
			write(desPtr, result);
		}

		fclose(sourcePtr);
		fclose(desPtr);
	}

}