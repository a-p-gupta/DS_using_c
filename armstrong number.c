#include <stdio.h>

int pow(int r,int d){
	int ans=1;
	while(d>0){
		ans=ans*r;
		d--;
	}
	return ans;	
}
void main(){
	int number,rem,sum=0,num,num2,digits=0;
	
	
		sum=0;
		printf("\nEnter a number : ");//153
		scanf("%d",&number);
		num=num2=number;
		
		while(num2>0){			// finds total digitts of number
			rem=num2%10;
			digits++;
			num2=num2/10;
		}
		
		while(number>0){
			rem=number%10;
			sum=sum+pow(rem,digits);
			number=number/10;
		}
		printf("sum is : %d\n",sum);
		if(num==sum){
			printf("%d is a armstone number",num);
		}
		else{
			printf("%d is not  armstone number",num);
		}
	
}
