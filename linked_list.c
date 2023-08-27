
// linked list 
// hash table  , in this collision occurs if remainder of two data will be same
#include <stdio.h>
#include <stdlib.h>
void viewlist();
struct student
{ 
  int enroll;
 struct student *link;
};
struct student *start;


//------------------------------------------Hashing functions --------------------------------------------------
struct student **hashTable;
int hashSize;

void setHashTableSize()			// create hash table
{
	int i;
	printf("\n\t\t\t creating Hash Table \n\n");
	printf("\nEnter h of n value/size of hash table : ");
	scanf("%d",&hashSize);
	hashTable=(struct student*)malloc(sizeof(struct student)*hashSize);	// create hash table dynamic 
	for(i=0;i<hashSize;i++)										// initialize hash table value to NULL
		hashTable[i]=NULL;
	printf("\nHash table create");
	getch();
}

void hashing(struct student **hashTable1, int size, struct student *node)		// entering element in hash table
{
	int value,r;			// r for remainder
	value=node->enroll;
	r= value % size;
	if(hashTable1[r] == NULL)
	{
		hashTable1[r]=node;
	}
	else
	printf("\n Already value present ");					// collision occurs 
	
}

void hashSearch(struct student **hashTable2 , int size)						// searching in hash table
{
	int value;
	printf("\nEnter enroll to be search : ");
	scanf("%d",&value);
	if(hashTable2[value%size] == NULL)
	{
		printf("\n Value not found in table");
		return;
	}
	else
	{
		if(hashTable2[value%size]->enroll == value)	
		{
			printf("\n%d found in Hash table ");
		}
		else
			printf("\nValue not found in Hash table");
	}	
}

void hashDelete(struct student **hashTable4, int size, struct student *node)		// deleting element in hash table
{
	hashTable4[node->enroll % size]=NULL;
}

void showHashData(struct student **hashTable3, int size)			// view hash table data
{
	int i;
	for(i=0;i<size;i++)
	{
		if(hashTable3[i] == NULL)
		{
		//	printf("\n %d index in table is empty ",i);
		}
		else
		{
			printf("\n %d index enroll is %d ",i,hashTable3[i]->enroll);
		}
		
	}
	getch();
}

//------------------------------------------Linked list --------------------------------------------------
void inserting_beg()
{  													 // 1)inserting at begining of list 
	struct student *n,*t;
	n=(struct student*)malloc(sizeof(struct student));
	printf("\nenter your enrollment : ");
	scanf("%d",&n->enroll);
	hashing(hashTable, hashSize,n);					// inserting in hash table
	t=start;
	start=n;
	n->link=t;
}
void inserting_l()
{
	viewlist();												 // 2)inserting at given locatin of list 
	int pos , i;
	struct student *n,*t,*k;
	n=(struct student*)malloc(sizeof(struct student));
	printf("\nEnter position to be insert : ");
	scanf("%d",&pos);

	printf("\nenter your enrollment : ");
	scanf("%d",&n->enroll);
	n->link=NULL;
	hashing(hashTable, hashSize,n);					// inserting in hash table
	t=start;

	for(i=0;i<pos-1;i++)
	{
		k=t;
		t=t->link;
		if(t==NULL)
		printf("\nposition is not valid ");
	}
	if(pos==1)
	{
		n->link=start;
		start=n;
	}
	else
	{	
		n->link=t;
		k->link=n;	
	}
	

}

void inserting_end()
{ 														 // 3)insert at end of list
	struct student *n,*t;
	n= (struct student*)malloc(sizeof(struct student));
	printf("\nenter enrollment no. : ");
	scanf("%d",&n->enroll);
	n->link=NULL;
	hashing(hashTable, hashSize,n);					// inserting in hash table
	if(start==NULL)
	start=n;
	else
	{
		t=start;
		while(t->link !=NULL)
		t=t->link;
		t->link=n;
	}
}

void deleting_beg()
{ 														 // 4) deleting at begining of list 
 struct student *t;

 if(start == NULL)
 {
 	printf("\nlist is empty");
 	return;
 }
  t=start;
 start=start->link;
 hashDelete(hashTable,hashSize,t); 						// node delete from hash table
  free(t);
   printf("\n element deleted ");
	
}

void deleting_l()										// 5) deleting at given locatin of list 
{
	viewlist();
	int pos,i;
	struct student *t,*k;
	printf("\nEnter position to be delete ");
	scanf("%d",&pos);
	t=start;
	for(i=0;i<pos-1;i++)
	{
		k=t;
		t=t->link;
	}
	k->link = t->link;
	hashDelete(hashTable,hashSize,t); 						// node delete from hash table
	free(t);
	 printf("\n element deleted ");

}

void deleting_end()
{  														 // 6) deleting at end of list 
  struct student *t,*p;
  t=start;
  while(t->link !=NULL)
  {
  	p=t;
  t=t->link;
  }
  p->link=NULL;
  hashDelete(hashTable,hashSize,t); 						// node delete from hash table
  free(t);
  printf("\n element deleted ");
  	
}


void searching()									// 7) Searching value in list
{
	viewlist();
	int value;
	struct student *t;
	printf("\nEnter a value to be search ");
	scanf("%d",&value);
	for(t=start ; t != NULL;t=t->link)
	{
		if(value == t->enroll)
		{
			printf("\nNumber found in list ");
			return;
		}
	}
	printf("\nNumber not found in list ");
}

void viewlist()											//8) view the list 
{
  struct student *t;
	t=start;
		while(t!=NULL)	
	{
		printf("\t************");
			t=t->link;

	}
		t=start;			// retset the t value
		printf("\n\t");
	while(t!=NULL)	
	{
		printf("*enroll : %d* => ",t->enroll);
		t=t->link;
	}
	printf("\t NULL");
		t=start;			// retset the t value
		printf("\n");

		while(t!=NULL)	
	{
		printf("\t************");
			t=t->link;

	}
	
}

void menu()
{
	int choice; 
	setHashTableSize();
  while(1)
   {
    system("cls");
   	printf("\n1) inserting at begining of list ");
	printf("\n2) inserting at location of list ");
   	printf("\n3) inserting at end of list ");
   	printf("\n4) deleting at begining of list ");
   	printf("\n5) deleting at location of list ");
   	printf("\n6) deleting at end of list ");
   	printf("\n7) Searching");
   	printf("\n8) Searching in hash table");
   	printf("\n9) viewlist");
   	printf("\n10) view hash table ");
   	printf("\n11) exit");
   	printf("\nenter your choice : " );
   	scanf("%d",&choice);
   	switch(choice)
   	{
   		case 1 :
   			inserting_beg();
   			break;
   		case 2:
   			inserting_l();
   			break;
   		case 3: 
   		    inserting_end();
   		    break;
   		case 4: 
		   deleting_beg();
		   getch();
		   break; 
		case 5: 
		   deleting_l();
		   getch();
		   break;  
   		case 6:
   			 deleting_end();
		   getch();
		   break; 
   		case 7:
   			searching();
   			getch();
   			break;
   		case 8:
   			hashSearch(hashTable , hashSize);
   			getch();
   			break;
   		case 9:
   				viewlist();
   				getch();
   				break;
   		case 10:
				showHashData(hashTable, hashSize);
   				getch();
   				break;
   		case 11: exit(0);
	   }
   }
}

void main()
{
	 //	clrscr();
	menu();
	getch();
}
