#include <stdio.h>

void main(){
	int number,rem,sum=0,rev=0;
	char c;
	printf("Enter a number : ");//153
	scanf("%d",&number);
	
	while(number>0){
		rem=number%10;
		sum=sum+rem;
		rev=rev*10+rem;
		number=number/10;
	}
	printf("sum is : %d",sum);
	printf("\nreverse is : %d",rev);
		
}
