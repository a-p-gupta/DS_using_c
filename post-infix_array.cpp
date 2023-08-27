#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define size 50
char stack[size];
int top=-1;
void push(char c)
{
	top++;
	stack[top]=c;
//	printf("pushed ");
}
char pop()
{
//	printf("poped  ");
	return(stack[top--]); 
}
int main()
{
 int n=11,i;
 char p[]={'a','b','d','*','+','e','f','-','*','g',   '+'};
 char a[50],b[50];
 printf("\t\t\tPostfix to Infix");
 /*
 printf("\n\n\nenter a size of expression : ");
 scanf("%d",&n);
 p=(char*)malloc(sizeof(char)*n);
 printf("enter a expression : ");
 for(i=0;i<n;i++)
 scanf("%c ",p[i]);
 */
 for(i=0;i<n;i++)
 { 
   int c;
  if(p[i]=='+' ||p[i]=='-' ||p[i]=='*' ||p[i]=='/' )
  {
  int	k=0,l=0,j;
   a[k]=pop();
  if(a[k]==')')
  	do{
  		 a[++k]=pop();
  	  }while(a[k]!='(');
  	  
  	b[l]=pop();  
  	 if(b[l]==')')
  	do{
  		 b[++l]=pop();
  	  }while(b[l]!='(');
  	
	  push('(');
	  for(j=l;j>=0;j--)  
  	  push(b[j]);
  	  push(p[i]);
  	  for(j=k;j>=0;j--)
  	  push(a[j]);
  	  push(')');
  }
  else
  push(p[i]);
   for(c=0;c<= top;c++)
 printf("%c ",stack[c]);
 printf("\n");
 }
 for(i=0;i<= top;i++)
 printf("%c ",stack[i]);
 
}
