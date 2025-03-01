#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Vigenere Cipher

//加密 
void encode(char plaintext[1000],char key[100]){
	int i,j;
	i=0;
	while (i<strlen(plaintext)){
		for (j=0;j<strlen(key);j++){
			if (plaintext[i]>='A'&&plaintext[i]<='Z'){
				plaintext[i]=((plaintext[i]-'A')+(key[j]-'A'))%26+'A';
			}
			else if (plaintext[i]>='a'&&plaintext[i]<='z'){
				plaintext[i]=((plaintext[i]-'a')+(key[j]-'a'))%26+'a';
			}
			i++;
		}
	}
	printf("加密後: %s\n\n",plaintext);
}

//解密 
void decode(char cyphertext[1000],char key[100]){
	int i,j;
	i=0;
	j=0;
	while (i<strlen(cyphertext)){
		if (j==strlen(key)){
			j=0;
		}
		if (cyphertext[i]>='A'&&cyphertext[i]<='Z'){
			cyphertext[i]=((cyphertext[i]-'A')-(key[j]-'A')+26)%26+'A';
			j++;
		}
		else if (cyphertext[i]>='a'&&cyphertext[i]<='z'){
			cyphertext[i]=((cyphertext[i]-'a')-(key[j]-'a')+26)%26+'a';
			j++;
		}
		i++;
	}
	printf("解密後: %s\n\n",cyphertext);
}

int main(){
	int n;
	char text[1000],key[100];
	
	//DPR AVBVSKBR SOIFABM BL K UNT SA AUD EUKBM UK CBNTNA VT WWZKXBF UP KBSPWEZ KVQ IYVIKXQRTMM, OAD EUKBM UK CBNTNA NZ DQZKC WS IRIYROVTK KVQ IYVGXYDRXCG.--ZGBBVT VCGNOZ XOXO
	printf("請選擇 :\n1. 加密\n2. 解密\n");
	while (scanf("%d",&n)!='EOF'){
		getchar();
		printf("請輸入文本:");
		scanf("%[^\n]",text);
		getchar();
		printf("請輸入密鑰:");
		scanf("%[^\n]",key);
		if (n==1){
			encode(text,key);
		}
		else if (n==2){
			decode(text,key);
		}
		else {
			printf("error");
		}
		printf("請選擇 :\n1. 加密\n2. 解密\n");
	}
	return 0;
}
