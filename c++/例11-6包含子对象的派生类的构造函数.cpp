#include <iostream>
#include <string>
using namespace std;

class student
{
public:
	student(int,string,char);
	~student(){}
	void display();
	//friend ostream & operator <<(ostream &,student &);
protected:
	int num;
	string name;
	char sex;
};

/*ostream & operator <<(ostream & output,student &s)
{
	output<<"num:"<<s.num<<endl;
	output<<"name:"<<s.name<<endl;
	output<<"sex:"<<s.sex<<endl;
	return output;
}*/

student::student(int n,string na,char s)
{
	num=n;
	name=na;
	sex=s;
}

void student::display()
{
	cout<<"num:"<<num<<endl;
	cout<<"name:"<<name<<endl;
	cout<<"sex:"<<sex<<endl;
}

class student1:public student
{
public:
	student1(int,string,char,int,string,int,string,char);
	void show();
	~student1(){}
private:
	int age;
	string addr;
	student monitor;
};

student1::student1(int n,string na,char s,int ag,string ad,int sn,string sna,char ss):student(n,na,s),monitor(sn,sna,ss)
{
	age=ag;
	addr=ad;
}

void student1::show()

{
	cout<<"monitor:"<<endl;
	monitor.display();
	display();
	cout<<"age:"<<age<<endl;
	cout<<"addr:"<<addr<<endl;
}

int main()
{
	student1 s1(166,"jake",'f',22,"america",167,"pip",'f');
	student1 s2(168,"mikcle",'m',23,"china",167,"pip",'f');
	s1.show();
	s2.show();
	return 0;
}