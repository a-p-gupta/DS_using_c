#include <stdio.h>
#include <conio.h>

int heap[15];
int i=-1;

void insertion(int h[])
{
	int j, data;
	printf("\nEnter number to be insert in heap : ");
	scanf("%d",&data);
	h[++i]=data;
	for(j=i; j!=0;)
	{
		if(data>h[(j-1)/2])
		{
			h[j]=h[(j-1)/2];
			j=(j-1)/2;		// through this we can jump to parent of any element
			if(j==0)
				h[j]=data;
			printf("\nif");
		}
		else
		{
			h[j]=data;
			printf("\nelse");
			break;
		}
		printf("\nfor");
	}
		viewHeap(h);
}

void deleting(int h[])
{
int data=h[i--];
int j=0;

	while(j!=i)
	if(h[j*2+1]<h[j*2+2])
	{
		h[j]=h[j*2+2];
		h[j*2+2]=data;
		j=j*2+2;		// through this we can jump to child element
		printf("\nif");	
	}
	else
	{
		h[j]=h[j*2+1];
		h[j*2+1]=data;
		j=j*2+1;
		printf("\nelse");
	}
 viewHeap(h);
}

void viewHeap(int h[])
{ int j;
	if(i==-1)
	printf("\nHeap is empty");
	for(j=0; j<=i;j++)
  printf("\t%d",h[j]);	
}

void main()
{
	int choice;
	while(1)
	{
		printf("\n1) insertion in heap ");
		printf("\n2) Deletion in heap ");
		printf("\n3) ViewHeap elements ");
		printf("\n4) Exit");
		printf("\nEnter your choice number : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insertion(heap);
				break;
			case 2: deleting(heap);
				break;	
			case 3: viewHeap(heap);
				break;
			case 4:	exit(0);
				
		}
	}
}
