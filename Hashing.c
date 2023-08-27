// hash table  , in this collision occurs if remainder of two data will be same
#include <stdio.h>
#include <stdlib.h>
struct student
{ 
  int enroll;
 struct student *link;
};
struct student **hashTable;
int hashSize;

void createHashTable()			// create hash table
{
	int i;
	printf("\n\t\t\t creating Hash Table \n\n");
	printf("\nEnter h of n value/size of hash table : ");
	scanf("%d",&hashSize);
	hashTable=(struct student*)malloc(sizeof(struct student)*hashSize);	// create hash table dynamic 
	for(i=0;i<hashSize;i++)										// initialize hash table value to NULL
		hashTable[i]=NULL;
	printf("\nHash table create");
	
}

void hashing(struct student **hashTable1, int size, struct student *node)		// entering element in hash table
{
	int value,r;			// r for remainder
	struct student *temp;
	value=node->enroll;
	r= value % size;

	if(hashTable1[r] == NULL)
	{
		hashTable1[r]=node;
	}
	else
	{
		for(temp=hashTable1[r]; temp->link!=NULL; temp=temp->link );
		temp->link=node;
	}
}

void hashSearch(struct student **hashTable2 , int size)						// searching in hash table
{
	int value;
	struct student *t;
	printf("\nEnter enroll to be search : ");
	scanf("%d",&value);
	if(hashTable2[value%size] == NULL)
	{
		printf("\n Value not found in table");
		return;
	}
	else
	{
		if(hashTable2[value%size]->enroll )	
		{
			for(t=hashTable[value%size]; t!=NULL; t=t->link)
			{
				if(t->enroll==value)
				{
				printf("\n%d found in Hash table ");
				return;
				}
			}
			printf("\nValue not found in Hash table");	
		}
		else
			printf("\nValue not found in Hash table");
	}	
}

void hashDelete(struct student **hashTable4, int size, struct student *node)		// deleting element in hash table
{
	struct student *t, *pre;
	
	if(hashTable4[node->enroll%size]->enroll == node->enroll)
	{
		t=hashTable4[node->enroll%size];
		hashTable4[node->enroll%size]=hashTable4[node->enroll%size]->link;
		free(t);
		return;
	}
	
	for(t=hashTable4[node->enroll%size]; t!=NULL; )
	{
		if(t->enroll==node->enroll)
		{
			pre->link=t->link;
			free(t);
			return;
		}
		pre=t;
		t=t->link;
	}
}

void showHashData(struct student **hashTable3, int size)			// view hash table data
{
	int i;
	struct student *t;
	for(i=0;i<size;i++)
	{
		if(hashTable3[i] == NULL)
		{
		//	printf("\n %d index in table is empty ",i);
		}
		else
		{
			for(t=hashTable[i]; t!=NULL; t=t->link)
			printf("\n %d index enroll is %d ",i,t->enroll);
		}
		
	}
}

void insert()
{
	struct student *new_node;
	new_node=(struct student*)malloc(sizeof(struct student));
	printf("\nEnter your enroll : ");
	scanf("%d",&new_node->enroll);
	new_node->link=NULL;
	hashing(hashTable, hashSize, new_node);
	
}

void deletion()
{
	struct student *new_node;
	new_node=(struct student*)malloc(sizeof(struct student));
	printf("\nEnter enroll to be delete : ");
	scanf("%d",&new_node->enroll);
	new_node->link=NULL;
	hashDelete(hashTable, hashSize, new_node);
}

void menu()
{
	int choice;
	while(1)
	{
		system("cls");
		printf("\n1) Create hash table ");
		printf("\n2) Insert in hash table ");
		printf("\n3) Delete from hash table ");
		printf("\n4) Searching in hash table ");
		printf("\n5) View hash table ");
		printf("\n6) Exit ");
		printf("\nEnter your choice number : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:	createHashTable();
			break;
			case 2:	insert();
				break;
				case 3:	deletion();
					break;
					case 4:	hashSearch(hashTable, hashSize);
						break;
						case 5:	showHashData(hashTable, hashSize);
							break;
							case 6: exit(0);
		}
		getch();
	}
}

void main()
{
	menu();	
}
