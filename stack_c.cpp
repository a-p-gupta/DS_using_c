#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define size 50
char stack[size];
int top=-1;
void push()
{
	stack[++top]=c;
//	printf("pushed ");
}
void pop()
{
//	printf("poped  ");
	printf("%c",stack[top--]); 
}

void main()
{
	int choice;
	while(1)
	{
		printf("\n1) Push");
		printf("\n2) Pop");
		printf("\n3) Display");
		printf("\n4) exit");
		printf("\n enter a choice number : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				case 2: 
				case 3:
					case 4: exit(0);
						
		}
	}
}
