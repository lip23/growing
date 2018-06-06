#include <iostream>
#include <string>
using namespace std;

class student
{
public:
	void get_value();
	void display();
private:
	int num;
	string name;
	char sex;
};

void student::get_value()
{
	cout<<"please input num name sex"<<endl;
	cin>>num>>name>>sex;
}

void student::display()
{
	cout<<"num:"<<num<<endl;
	cout<<"name:"<<name<<endl;
	cout<<"sex:"<<sex<<endl;
}

class stu1:public student
{
public:
	void get_value1();
	void display_1();
private:
	int age;
	string addr;
};

void stu1::get_value1()
{
	cout<<"please input age addr"<<endl;
	cin>>age>>addr;
}

void stu1::display_1()
{
	cout<<"age:"<<age<<endl;
	cout<<"addr:"<<addr<<endl;
}

int main()
{
	stu1 s;
	s.get_value();
	s.get_value1();
	s.display();
	s.display_1();
	return 0;
}