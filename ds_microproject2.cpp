
// mutable/ flexible stack without using array 
#include <iostream>
#include <conio.h>
using namespace std;

class student 
{
	
	int enroll;
	string name;
	int age;
	long int mobile;
	public :
	void getdata();
	void showdata();
};
void student :: getdata()
{
	cout<<"\nEnrollment : ";
	cin>>enroll;
	cout<<"name : ";
	cin>>name;
	cout<<"age : ";
	cin>>age;
	cout<<"mobile : ";
	cin>>mobile;
	cout<<"\n\nData push successfully , press enter  ";
	getch();
	getch();
}
void student :: showdata()
{
	cout<<"\n\nEnrollment : "<<enroll;
	cout<<"\nName : "<<name;
	cout<<"\nAge: "<<age;
	cout<<"\nMobile : "<<mobile;
}

int top=-1;

void push(student* stack)
{
	(stack+(++top))->getdata();
}
void pop(student *stack)
{
	if(top==-1)
	cout<<"\nstack underflow";
	else
	(stack+(top--))->showdata();
}
void display(student *stack)
{
	int i;
	cout<<"\n\n\t\t Display all students data";
	for(i=top;i>=0;i--)
	{
		(stack+i)->showdata();
	}
	
}
int main(int argc, char *argv[])
{ 
student *p;

while (1)
	{ // system("cls");
		cout<<"\n\n\n1) Push student data";
		cout<<"\n2) Pop student data ";
		cout<<"\n3) Display student data ";
		cout<<"\n4) exit";
		int choice;
		cout << "\nenter your choice no.";
		cin >> choice;
		switch (choice)
		{
		case 1:
			push(p);
			break;
		case 2:
			pop(p);
			break;
		case 3: 
			display(p);
			break;
		case 4:
			exit(0);
			
		}
	} 

}
