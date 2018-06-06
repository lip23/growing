#include <iostream>
#include <string>
using namespace std;

class student
{
public:

protected:
	int num;
	string name;
	char sex;
};

class stu1:protected student
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
	cout<<"please input num name sex age addr"<<endl;
	cin>>num>>name>>sex>>age>>addr;
}

void stu1::display_1()
{
	cout<<"num:"<<num<<endl;
	cout<<"name:"<<name<<endl;
	cout<<"sex:"<<sex<<endl;
	cout<<"age:"<<age<<endl;
	cout<<"addr:"<<addr<<endl;
}

int main()
{
	stu1 s;
	s.get_value1();
	s.display_1();
	return 0;
}