#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//RailFence

void encrypt(char text[1000],int key){
	int len = strlen(text);
	char fence[key][len];
	char ciphertext[1000];
	int i,j,index=0;
	int row=0,col=0,direction=1;

	//初始化陣列
	for (i=0;i<key;i++){
		for (j=0;j<len;j++){
			fence[i][j]='\n';
		}
	}

	//填充柵欄
	for (i=0;i<len;i++){
		fence[row][col]=text[i];
		row += direction;
		col += 1;
		if (row==0 || row==key-1){
			direction = -direction;
		}
	}

	//轉成密文
	for (i=0;i<key;i++){
		for(j=0;j<len;j++){
			if(fence[i][j]!='\n'){
				ciphertext[index]=fence[i][j];
				index++;
			}
		}
	}
	ciphertext[index]='\0';

	printf("%s\n",ciphertext);
}

void decrypt(char text[1000],int key){
    int len = strlen(text);
    char fence[key][len];
    char plaintext[1000];
    int i, j, index = 0;
    int row = 0, col = 0, direction = 1;

    // 初始化柵欄
    for (i = 0; i < key; i++) {
        for (j = 0; j < len; j++) {
            fence[i][j] = '\n';
        }
    }

    // 標記柵欄填充路徑
    for (i = 0; i < len; i++) {
        fence[row][col] = '*';
        row += direction;
        col++;
        if (row == 0 || row == key - 1) {
            direction = -direction;
        }
    }

    // 按照標記填充密文字符
    for (i = 0; i < key; i++) {
        for (j = 0; j < len; j++) {
            if (fence[i][j] == '*' && index < len) {
                fence[i][j] = text[index];
                index++;
            }
        }
    }

    // 重新按照加密時的路徑讀取明文
    row = 0, col = 0, direction = 1;
    for (i = 0; i < len; i++) {
        plaintext[i] = fence[row][col];
        row += direction;
        col++;
        if (row == 0 || row == key - 1) {
            direction = -direction;
        }
    }
    plaintext[len] = '\0';

    printf("%s\n", plaintext);
}

int main(){
	int n;
	char text[1000];
	int key;

    //CYTGAHITEROWIIGROVNCDSRPORPYSHATFRTNOSLIGOE

	printf("請選擇 :\n1. 加密\n2. 解密\n");
	while (scanf("%d",&n)!='EOF'){
		getchar();
		printf("請輸入文本:");
		scanf("%[^\n]",text);
		getchar();
		printf("請輸入密鑰:");
		scanf("%d",&key);
		if (n==1){
			encrypt(text,key);
		}
		else if (n==2){
			decrypt(text,key);
		}
		else {
			printf("error");
		}
		printf("請選擇 :\n1. 加密\n2. 解密\n");
	}


	return 0;
}
