
#include"Header.h"



void encode(char *enter, char *output) {

	int lens=-1;                                          
	for (int a = 0; enter[a - 1] != '\0'; a++) {			//計算檔案中URL長度
		lens++;
	}                                              

	if (enter[lens - 1] != '\n') {								//最後一句若無換行符號，需+1(原<times 為了略過換行符號)
		lens++;
	}
	
	
	int locate = 0;											    //output的字元位置
	for (int i = 1; i < lens; i++) {

		if (!(isalnum(enter[i-1]) || (enter[i - 1] == '.'))) {	//isalnum 判斷使否為英文或數字
			output[locate] = '%';
			locate++;
			output[locate] = hexadecimal(enter[i - 1], 1);//16進位第一個數
			locate++;
			output[locate] = hexadecimal(enter[i - 1], 2);//第二個數
			locate++;
		}
		else {
			output[locate] = enter[i - 1];
			locate++;
		}
	}
	output[locate] = '\0';												//字尾補上結束字元
	puts(output);
}

char hexadecimal(int asc, int locate) {            //16位元編碼
	char base16[] = "0123456789ABCDEF";
	if (locate == 1) {                        //第一個數字為 10進位碼/16 整位數部分
		return base16[asc / 16];
	}
	else {
		return base16[asc % 16];			//第二個數字 10進位碼/16 餘數部分
	}
}


void write(FILE *fPtr, char content[]) {
	for (int index = 0; content[index] != '\0'; index++) {
		fputc(content[index], fPtr);           //fputc() 從將字元一個一個的放到檔案中
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

		while (fgets(input, 256, sourcePtr) != NULL) {        //fgets(輸入資料的陣列,該行最多幾個字元,檔案指標)從檔案讀取資料
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