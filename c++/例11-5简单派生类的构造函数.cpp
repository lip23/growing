#include <iostream>
#include <string>
using namespace std;

class student
{
public:
	student(int,string,char);
	~student(){}
protected:
	int num;
	string name;
	char sex;
};

student::student(int n,string na,char s)
{
	num=n;
	name=na;
	sex=s;
}

class student1:public student
{
public:
	student1(int,string,char,int,string);
	void show();
	~student1(){}
private:
	int age;
	string addr;
};

student1::student1(int n,string na,char s,int ag,string ad):student(n,na,s)
{
	age=ag;
	addr=ad;
}

void student1::show()
{
	cout<<"num:"<<num<<endl;
	cout<<"name:"<<name<<endl;
	cout<<"sex:"<<sex<<endl;
	cout<<"age:"<<age<<endl;
	cout<<"addr:"<<addr<<endl;
}

int main()
{
	student1 s1(166,"jake",'f',22,"america");
	student1 s2(168,"mikcle",'m',23,"china");
	s1.show();
	s2.show();
	return 0;
}


