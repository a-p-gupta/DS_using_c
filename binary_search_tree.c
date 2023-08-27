#include <stdio.h>
#include <conio.h>

struct student 
{
	int enroll;
	struct student *left , *right;
};
struct student *root=NULL;
void add()
{
  struct student *t , *temp;
  t=(struct student*)malloc(sizeof(struct student));
  printf("\nEnter enroll number : ");
  scanf("%d",&t->enroll);
  	t->left=NULL;
  	t->right=NULL;
  if(root==NULL)
  {
  	root=t;
  }	
  else
  {
  	for(temp=root;temp!=NULL;)
  	{
  		if(t->enroll< temp->enroll)
		  {
		  	if(temp->left==NULL)
		  	{
		  	temp->left=t;
		  	break;
		    }
		  	temp=temp->left;
		  }
		  else
		  {
		  	if(temp->right==NULL)
		  	{
		  	temp->right=t;
		  	break;
		    }
		  	temp=temp->right;
		  }		
    }	
  }
}

struct student* leftmostnumber(struct student *t)
{
	t=t->left;
	while(t->right!=NULL)
	{
		t=t->right;
	}
	return t;
}

struct student* rightmostnumber(struct student *t)
{
	printf("\nin rightmost : %d",t->enroll);
	t=t->right;
	while(t->left!=NULL)
	{
		t=t->left;
	}
	printf("\nreturn rightmost number : %d",t->enroll);
	return t;
}
//----------------------------------------DELETION ------------------------------------------------------
struct student* deleting (struct student *root , int data)
{
	struct student *t, *n , *temp, *prev;
	if(root==NULL)
	{
		printf("\nTree is empty");
		return NULL;
	}
	n=(struct student*)malloc(sizeof(struct student));
	n->enroll= data;
	
	for(t=root;t!=NULL;)
	{  
		if(t->enroll > n->enroll)
		{
			if(t->left==NULL)
			{
			printf("\nValue not found");
			return NULL;
			}
				prev=t; 
			t=t->left;
		}
		else if(t->enroll < n->enroll)
		{
			if(t->right==NULL)
			{
			printf("\nValue not found");
			return NULL;
			}
				prev=t; 
			t=t->right;
		}
		else
		{
			if(t->left==NULL && t->right==NULL)
			{	printf("\n if start");
					//	free(t); 
				printf("\n%d",t->enroll); 
				if(prev->left==t)
				{
				prev->left=NULL;
				 free(t);
				}
				else
				{
				prev->right=NULL;
				 free(t);
				}
					printf("\n%d",t->enroll); 
					printf("\n if end");
				return NULL;
			}
			else if(t->left==NULL && t->right !=NULL)
			{ 	printf("\n else if start");
				int value;
				temp=rightmostnumber(t);
				value=temp->enroll;
				deleting(t,temp->enroll);
				t->enroll= value;
				printf("\n else if end");
				return NULL;
			}
			else if(t->left !=NULL)
			{	printf("\n else if1 start");
				temp=leftmostnumber(t);
				int value=temp->enroll;
				deleting(t,temp->enroll);
				t->enroll= value;
				printf("\n else if1 end");
				return NULL;
			}
		
		}

	}
	
}
 
 //-------------------------------------------searching-----------------------------------
 struct student* searching(struct student *root )
{
	struct student *t, *n , *temp, *prev;
	if(root==NULL)
	{
		printf("\nTree is empty");
		return NULL;
	}
	n=(struct student*)malloc(sizeof(struct student));
	printf("\nEnter value to be search in tree : ");
	scanf("%d",&n->enroll);
	
	for(t=root;t!=NULL;)
	{  
		if(t->enroll > n->enroll)
		{
			if(t->left==NULL)
			{
			printf("\nValue not found");
			return NULL;
			}
				prev=t; 
			t=t->left;
		}
		else if(t->enroll < n->enroll)
		{
			if(t->right==NULL)
			{
			printf("\nValue not found");
			return NULL;
			}
				prev=t; 
			t=t->right;
		}
		else
		{
			printf("%d found in array ",t->enroll);
		}

	}
	
}

void preorder(struct student *t)
{
	if(t!=NULL)
	{
 		printf("%d ",t->enroll);
 		preorder(t->left);
 		preorder(t->right);
	}
	else
	return;
 	
}

void postorder(struct student *t)
{
	if(t!=NULL)
	{
 		postorder(t->left);
 		postorder(t->right);
 		printf("%d ",t->enroll);
	}
	else
	return;
 	
}

void inorder(struct student *t)
{
	if(t!=NULL)
	{
 		inorder(t->left);
 		printf("%d ",t->enroll);
 		inorder(t->right);
	}
	else
	return;
 	
}

void main()
{
	int choice, data;
	while(1)
	{
	printf("\n1) Add element in tree ");
	printf("\n2) Delete element in tree ");
	printf("\n3) preorder ");
	printf("\n4) inorder ");
	printf("\n5) postorder ");
	printf("\n6) Search element in tree ");	
	printf("\n7) exit ");
	printf("\nEnter your choice number : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: add();
				break;
		case 2: printf("\nEnter enroll for delete : ");
				scanf("%d",&data);
		 deleting(root,data);
				break;
		case 3: preorder(root);
				break;
		case 4: inorder(root);
				break;
		case 5: postorder(root);
				break;
		case 6: searching(root);
				break;
		case 7: exit(0);
	}
	}
}
