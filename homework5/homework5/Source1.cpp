#include"Header.h"

 
void decode(char *input, char *output) {

	int lens = -1;
	for (int a = 0; input[a - 1] != '\0'; a++) {			//計算檔案中URL長度
		lens++;
	}

	int locate = 0;													//output的字元位置

	if (input[lens - 1] != '\n') {								//最後一句若無換行符號，需+1(原<times 為了略過換行符號)
		lens++;
	}

	for (int i = 1; i < lens; i++) {  //<為了略過換行符號

		if ((input[i - 1] == '%') && (isxdigit(input[i])) && (isxdigit(input[i + 1]))) {	//驗證%後是否接二個十六進位，是則轉
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
	output[locate] = '\0';												//字尾補上結束字元
	puts(output);
}

char decimal(char first, char last) {     //10位元編碼
	char base16[] = "0123456789ABCDEF";
	int seg = 0;
	int ans;
	while (first != base16[seg]) {
		seg++;
	}
	ans = seg * 16;                    //16進位轉回成10進位 
	seg = 0;
	while (last != base16[seg]) {
		seg++;
	}
	ans = ans + seg;
	return ans;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//


int main(int argc, char *argv[]) { //argc 參數總數 argv[] 參數位址
	if (argc > 1) {
		if (strcmp(argv[1], "e") == 0 && argc == 4) {    //strcmp(a,b) 比對a,b是否相等
			enorde(argv[2], argv[3], 'e');
			printf("檔案成立\n");
		}
		else if (strcmp(argv[1], "d") == 0 && argc == 4) {
			enorde(argv[2], argv[3], 'd');
			puts("");
			printf("檔案成立\n");
		}
		else {
			printf("檔案成立 \n");
		}
	}
	
	return 0;
	system("pause");
}