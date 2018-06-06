#include <iostream>
#include <string>
using namespace std;

class student 
{
public:
	student(int n,string b,char s,int a);
	void show();
private:
	int num;
	string name;
	char sex;
	int age;
};

student::student(int n,string b,char s,int a)
{
	num=n;
	name=b;
	sex=s;
	age=a;
}

void student::show()
{
	cout<<"num:"<<num<<endl;
	cout<<"name:"<<name<<endl;
	cout<<"sex:"<<sex<<endl;
	cout<<"age:"<<age<<endl;
}

class graduate:public student
{
public:
	graduate(int n,string b,char s,int a,int w);
	void display();
private:
	int wage;
};

graduate::graduate(int n,string b,char s,int a,int w):student(n,b,s,a)
{
	wage=w;
}

void graduate::display()
{
	show();
	cout<<"wage:"<<wage<<endl;
}

int main()
{
	graduate g(168,"messy",'f',23,16666);
	student * p;
	p=&g;
	p->show();
	return 0;
}
