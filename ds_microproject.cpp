// college manegement system

#include <iostream>
#include <conio.h>
using namespace std;
class department;
class student;
class teacher;
class hod;
void menu();

void clear()
{
	system("cls");
	cout << "\t\t\t***********************************\n";
	cout << "\t\t\t*   College Manegement   System   *\n";
	cout << "\t\t\t***********************************\n";
	
}
//---------------
class people
{
  public:
	string name;
	int age;
	string gender;
	string qualification;
};
//-----------------------
class teacher : people
{
  public:
	string subject;
	teacher *link;
	void getdata();
	void showdata();
};
void teacher ::getdata()
{
	clear();
	cout << "\n\t\t\t TECHER INFORMATION";
	cout << "\n\n\nEnter your name : ";
	cin >> name;
	cout << "Enter your age : ";
	cin >> age;
	cout << "Enter your gender : ";
	cin >> gender;
	cout << "Qualification : ";
	cin >> qualification;
	cout << "Enter your subject name : ";
	cin >> subject;
}
void teacher ::showdata()
{
	cout<<"\n\t\tTEACHER INFORMATION";
	cout << "\n Name         : " << name;
	cout << "\n Age          : " << age;
	cout << "\n Gender       : " << gender;
	cout << "\n Qualifiation : " << qualification;
}
//----------------
class hod : people
{
  public:
	//	string department;
	teacher *a = NULL;
	void getdata();
	void showdata();
	void inserting();
};
void hod ::getdata()
{
	clear();
	cout << "\n\t\t\tHOD INFORMATION";
	cout << "\n\n\nEnter your name : ";
	cin >> name;
	cout << "Enter your age : ";
	cin >> age;
	cout << "Enter your gender : ";
	cin >> gender;
	cout << "Qualification : ";
	cin >> qualification;
	cout<<"\nInsert data successfully ";
	getch();
}
void hod ::showdata()
{
	cout<<"\n\t\tHOD INFORMATION";
	cout << "\n Name         : " << name;
	cout << "\n Age          : " << age;
	cout << "\n Gender       : " << gender;
	cout << "\n Qualifiation : " << qualification;
	
}
//@@@@@@@@@@@@@@@@@@@@
void hod ::inserting()
{

	teacher *te = new teacher;
	te->getdata();
	te->link = NULL;
	if (a == NULL)
		a = te;
	else
	{
		teacher *t;
		t = a;
		while (t->link != NULL)
			t = t->link;
		t->link = te;
	}
}
//---------------
class department
{
  public:
	string depart;
	department *link;
	void getdata();
	void showdata();
	void add_t();
	hod h;
};

void department ::getdata()
{
	clear();
	cout << "\nEnter  department name : ";
	cin >> depart;
	h.getdata();

}
void department ::showdata()
{
	cout<<"\n\t\tDEPARTMENT ";
	cout << "\n Department : " << depart;
	
}

void department :: add_t()
{
	
	h.inserting();
}

//------------------------------------------------------------------------------------------------------
class principal : people
{
  public:
	string college;
	department *d = NULL;
	void getdata();
	void showdata();
	void create_d();
	void show_d();
};
void principal ::getdata()
{
	clear();
	cout << "Enter college name : ";
	cin >> college;
	cout << "Enter your name : ";
	cin >> name;
	cout << "Enter your age : ";
	cin >> age;
	cout << "Enter your gender : ";
	cin >> gender;
	cout << "Qualification : ";
	cin >> qualification;
}
void principal ::showdata()
{
		clear();
		cout << "\t\t\t*************\n";
	cout << "\t\t\t*   "<<college<<"                                  *\n";
	cout << "\t\t\t*************\n";
	cout<<"\n\t\tPRINCIPAL INFORMATION";
	cout << "\n Name         : " << name;
	cout << "\n Age          : " << age;
	cout << "\n Gender       : " << gender;
	cout << "\n Qualifiation : " << qualification;
	
}
//@@@@@@@@@@@@@@@
void principal ::create_d()
{
	department *n = new department;
	n->getdata();
	n->link = NULL;
	if (d == NULL)
		d = n;
	else
	{
		department *de;
		de = d;
		while (de->link != NULL)
			de = de->link;
		de->link = n;
	}

}

void principal :: show_d()
{
	department *dp=d;
	if(dp==NULL)
	cout<<"\nTheir is no department";
	else
     {
      	while(dp !=NULL)
      	{
      		dp->showdata();
      		dp=dp->link;
      	}
      
      cout<<"\nEnter department name to add : ";
      string name;
      cin>>name;
      dp=d;
      while(dp != NULL)
      {
      	if(dp->depart ==name)
      		dp->add_t();
      	dp=dp->link;
   	}
     }
}


void menu()
{
	int choice;
	principal p;
//		p.getdata();
	getch();
	getch() ;
	while(1)
	{
		system("cls");
		clear();
	cout<<"\n1) Add department ";
	cout<<"\n2) Add teachers ";
	cout<<"\n3) Add students ";
	cout<<"\n4) exit";
	cout<<"\nEnter your choice no. : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		  p.create_d();
	           	break;
		case 2:
		  p.show_d();
		           break;
		case 3:
		          break;
		case 4: exit(0);
		
	}
	}
	
}

int main()
{
	/*
	p.getdata();
	getch();
	getch() ; */
	 menu();
/*	p.create_d();
	p.showdata();
	*/
}
