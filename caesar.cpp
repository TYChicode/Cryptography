#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ciphetext(char plaintext[50],int key){
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

int main(){
	int key;
	char name[50];
	scanf("%s %d",name,&key);
	ciphetext(name,key);
	return 0;	
}


