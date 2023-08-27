#include<stdio.h>
int size=5;
char stack[5];
top=-1;

void push(char c)
{
	top++;
	stack[top]=c;
}

char pop()
{
	return(stack[top--]);
}
void main()
{
	int size,i;
	printf("Enter a size of array : ");
	scanf("%d",&size);
	char *a=(char*)malloc(sizeof(char)*size);
	printf("Enter an expresion : ");
	for(i=0;i<size;i++)
	scanf("%c",&a[i]);
	
	for(i=0;i<size;i++)
	{ char x,y,c;
		if(a[i]=='+' ||a[i]=='-' ||a[i]=='*' ||a[i]=='/' ||a[i]=='^' )
		{
			y=pop();
			x=pop();
		 	c=x+y;
		 	push(c);
		}
		else
		push(a[i]);	
	}
	printf("\ninfix : %c ",pop());
}
