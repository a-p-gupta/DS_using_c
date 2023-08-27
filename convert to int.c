#include <stdio.h>
#include <string.h>
void main(){
	char a[30]={"one four aawawa "};
	char b[10]={" "};
	char character[30][10]={
	"one","aawawa","two","four"};
	int number[30]={1,2,3,4};
	int i,j,k=0;
	
	
	for(i=0;i<strlen(a);i++){
		if(a[i]==' '){
				printf("%d",i);
				printf("%s",b);
			for(j=0;j<strlen(character);j++){
				if(strcmp(b,character[j])==0){
					printf("%s\n",character[j]);
				}
			}
			k=0;
			memset(b,0,sizeof(b));
//			strcpy(b," ");
				printf("%s",b);
//			continue;
		}
		
		if(a[i]>='a' && a[i]<='z'){
			b[k++]=a[i];
		}
	}
}
