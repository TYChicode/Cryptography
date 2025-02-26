#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//加密
//使用ascii code做運算
void ciphetext(char plaintext[100],int key){
	int i;
	//對每個字元向右偏移n個，key為n
	for(i=0;i<strlen(plaintext);i++){
		if(plaintext[i]>='A'&&plaintext[i]<='Z'){
			plaintext[i]+=key;
		}
		else if(plaintext[i]>='a'&&plaintext[i]<='z'){
			plaintext[i]+=key;
		}
	}
	printf("%s ,key=%d\n",plaintext,key);
}

//解密
//使用ascii code做運算
void decode(char str[100]){
	int i,j;
	char ciphetext[100];

    //列出偏移量1~25的結果
	for(j=1;j<26;j++){
        strcpy(ciphetext,str);
		for(i=0;i<strlen(ciphetext);i++){
			if(ciphetext[i]>='A'&&ciphetext[i]<='Z'){
				ciphetext[i]-=j;
				if (ciphetext[i]<'A'){
                    ciphetext[i]+=26;
				}
			}
			else if(ciphetext[i]>='a'&&ciphetext[i]<='z'){
				ciphetext[i]-=j;
				if (ciphetext[i]<'a'){
                    ciphetext[i]+=26;
				}
			}
		}
		//查看偏移後的結果，找出偏移後有意義的字串
		printf("key=%2d,%s\n",j,ciphetext);
	}
}

int main(){
	int a,key;
	char str[100];
	//Wfleuvu ze 1961, Wvex Tyzr Lezmvijzkp nrj ivjkiltklivu zekf r lezmvijzkp ze 1980.
	printf("請輸入要執行的指令:\n1.加密\n2.解密\n");

	scanf("%d",&a);

	if (a==1){
        scanf("%s %d",str,&key);
        ciphetext(str,key);
	}
	else if(a==2){
        while(getchar()!='\n');
        scanf("%[^\n]",str);
        decode(str);
	}

	return 0;
}

