#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ciphetext(char plaintext[100],int key){
	int i;	
	for(i=0;i<strlen(plaintext);i++){
		if(plaintext[i]>64&&plaintext[i]<91){
			plaintext[i]+=key;
		}
		else if(plaintext[i]>96&&plaintext[i]<123){
			plaintext[i]+=key;
		}
	}
	printf("%s ,key=%d\n",plaintext,key);
}

void decode(char ciphetext[100]){
	int i,j;	
	for(j=1;j<25;j++){
		for(i=0;i<strlen(ciphetext);i++){
			if(ciphetext[i]>64&&ciphetext[i]<91){
				ciphetext[i]+=j;
			}
			else if(ciphetext[i]>96&&ciphetext[i]<123){
				ciphetext[i]+=j;
			}
		}
		printf("key=%d,%s\n",j,ciphetext);
	}
}

int main(){
	int key;
	char str[100];
	//scanf("%s %d",str,&key);
	//ciphetext(str,key);
	
	//Wfleuvu ze 1961, Wvex Tyzr Lezmvijzkp nrj ivjkiltklivu zekf r lezmvijzkp ze 1980.
	scanf("%s",str);
	decode(str);
	return 0;	
}


