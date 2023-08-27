// mutable 
#include<stdio.h>
#include<conio.h>
int main(int argc, char *argv[])
{
	char *a,i=-1,j;
	printf("enter elements in array : ");
	do{
	scanf("%c",(a+(++i)));
	printf("%c",*(a+i));

	}while(*(a+i)!='\n');
	
	// Alternative method for printing array
	i=-1;
	do{
	printf("%c ",*(a+(++i)));
	}while(*(a+i)!='\n'); 
	
	for(j=0;j<=i;j++)
	{
		printf("%c",*(a+j));
	}
}
