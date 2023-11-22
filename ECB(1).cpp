#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	int n,i,key,j;
	char plaintext[100][100],ch;
	printf("Enter the no of plain text:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter plaintext[%d]:",i+1);
		scanf("%s",&plaintext[i]);
	}
	printf("Enter the key:");
	scanf("%d",&key);
    for(i=0;i<n;i++){
    	printf("The words[%d]:%s\n",i+1,plaintext[i]);
    }
    for(i=0;i<n;i++)
	for(j=0;plaintext[i][j]!='\0';j++){
		ch=plaintext[i][j];
		if(isalnum(ch)){
			ch=(ch-'a'+key)%26 +'a';
		}
		plaintext[i][j]=ch;	
	}
	printf("The encrypted texts are:");
	for(i=0;i<n;i++){
		printf("The encrypted cipher text of[%d] is:%s\n",i+1,plaintext[i]);
	}
	return 0;}

