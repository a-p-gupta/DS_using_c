#include <iostream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>

using namespace std;
class student
{
	public :
	int enroll;
	string name;
	void getdata();
	void showdata();
	
};
void student :: getdata()
{
	cout<<"\nenter enrollment : ";
	cin>>enroll;
	cout<<"\nenter name : ";
	cin>>name;
}
void student :: showdata()
{
	cout<<"\nenrollment : "<<enroll;
	cout<<"\nName : "<<name;
}
int main()
{
 student *p;
// p=(student*)malloc(sizeof(student));
 p->enroll=2;	
 p->name="abhay";
 p->showdata(); 
}
