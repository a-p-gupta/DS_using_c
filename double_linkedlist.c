#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct student
{ 
  int enroll;
 struct student *pre,*post;
};
struct student *start=NULL;
struct student *end=NULL;
void insert_end()
{
																//1) inserting at end of list through start pointer 
	struct student *s;
	s=(struct student*)malloc(sizeof(struct student));
	printf("Enter a enrllment no : ");
	scanf("%d",&s->enroll);
	s->pre=NULL;
	s->post=NULL;
	if(start==NULL){
		start=s;
		end=s; 
	}
	else 
	{
		 struct student *t;
		 for(t=start;t->post!=NULL;t=t->post);			// this for loop has no body
		 
		 t->post=s;
		 s->pre=t;
		 end=s;
	}
}


void insert_end1()												// 2) inserting at end of list through end pointer
{
	struct student *s;
	s=(struct student*)malloc(sizeof(struct student));
	printf("Enter a enrllment no : ");
	scanf("%d",&s->enroll);

	s->post=NULL;
	printf(" 1 ");
	s->pre=end;
	
	if(end==NULL){
		end=s;
		start=s;
	}else{
		end->post=s;
		end=s;
	}
}

void insert_beg()
{
																// 3) inserting at start of list
	struct student *s;
	s=(struct student*)malloc(sizeof(struct student));
	printf("Enter a enrllment no : ");
	scanf("%d",&s->enroll);
	s->pre=NULL;
	s->post=start;
	if(start==NULL)
	{
	start=s;
	end=s;
	}
	else
	{
	start->pre=s;
	start=s;
	}
}

void insert_l()
{	

	viewlist_s();														// 4) inserting at location of list
	int pos , i;
	struct student *s,*t;
	t=start;
	s=(struct student*)malloc(sizeof(struct student));
	printf("\nEnter position to be insert : ");
	scanf("%d",&pos);
	printf("Enter a enrollment no : ");
	scanf("%d",&s->enroll);
	for(i=0;i<pos-1;i++)
	{
		t=t->post;
		if(t==NULL){
			printf("\nInvalid position ");
		}
	}
	if(pos==1)
	{
		s->pre=NULL;
		s->post=start;
		start=s;
		end=s;
	}
	else
	{
		s->pre=t->pre;
		s->post=t;
		t->pre=s;
		(s->pre	)->post=s;
	}
}

void deleting_end()										  // 5) deleting at end try remain
{
	struct student *t;
	t=end;
	end=end->pre;
	end->post=NULL;
	free(t);
}

void deleting_start()  									// 6) deleting at start try remain
{
	struct student *t;
	t=start;
	start=start->post;
	start->pre=NULL;
	free(t);
}

void deleting_l()									// 7) deleting at location of list
{
	struct student *t=start ,*temp;
	int pos,i;
	printf("\nEnter position to be delete : ");
	scanf("%d",&pos);
	if(pos==0)
	printf("\nPosition is invalid ");
	for(i=0;i<pos-1;i++)
	{
		t=t->post;
		if(t==NULL)
		printf("\nPosition is invalid");
	}
	temp=t;
	temp->pre->post=temp->post;
	temp->post->pre=temp->pre;
	free(temp);
}


void viewlist_s()
{														 // 8) view from starting
 struct student *v;
 for( v=start;v!=NULL;v=v->post)	
	printf("\nEnrollment : %d",v->enroll);
}

void viewlist_e()
{ 														// 9) view from ending
 struct student *v;
 for( v=end;v!=NULL;v=v->pre)	
	printf("\nEnroll : %d",v->enroll);
}

void searching()										// 10) searching in linklist
{
	struct student *t;
	int value,flag=0;
	printf("Enter enroll for searching : ");
	scanf("%d",&value);
	for(t=start;t!=NULL;t=t->post)
	{
		if(value==t->enroll)
		{
			flag=1;
			printf("\nvalue found in list ");
		}
	}
	if(flag==0)
	printf("\nValue not found in list");
}
void menu()
{ int choice;
	while(1)
	{
	  system("cls");
	  printf("\n1) Inserting data at starting of list");
	  printf("\n2) Inserting data at location of list");
  	  printf("\n3) Inserting data at ending  of list");
  	  printf("\n4) Deleting data at starting  of list");
  	  printf("\n5) Deleting data at location  of list");
  	  printf("\n6) Deleting data at ending  of list");
	  printf("\n7) Viewlist from staring ");
	  printf("\n8) Viewlist from ending ");
	  printf("\n9) Searching in list");
	  printf("\n10)Exit");
	  printf("\nEnter choice number :");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	  	case 1: insert_beg();
	  	     	break;
	  	case 2:  insert_l();
		  		break;     	
		case 3: insert_end1();
				break;
	  	case 4: deleting_start();
	  			break;
	  	case 5: deleting_l();
	  			break;
	  	case 6: deleting_end();
	  			break;
	  	case 7:  viewlist_s();
	  		getch();
	  			break;
	  	case 8: viewlist_e();
	  	 	getch();
		  		break;		
		case 9: searching();
			getch();
				break;
		case 10: exit(0);
	  }
	}
	
}
int main()
{
 	menu();
}
      
