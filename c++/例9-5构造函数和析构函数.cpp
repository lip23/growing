#include <iostream>
#include <string>
using namespace std;

class student
{
private:
	string num;
	string name;
	char sex;
public:
	student(string,string,char);
	~student();
	void display();
};

int main()
{
	student s("10011","zhang_fang",'m');
	s.display();
	student k("10010","wang_li",'f');
	k.display();
	return 0;
}

student::student(string n,string na,char m)
{
	cout<<"constructor called."<<endl;
	num=n;
	name=na;
	sex=m;
}

void student::display()
{
	cout<<"num:"<<num<<endl;
	cout<<"name:"<<name<<endl;
	cout<<"sex:"<<sex<<endl;
}

student::~student()
{
	cout<<"destructor called;"<<endl;
}
