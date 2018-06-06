#include <iostream>
using namespace std;

class student
{
public:
	student(int,double);
	void change(int ,double);
	void display();
private:
	int num;
	double score;
};

int main()
{
	student s(101,78.5);
	s.display();
	void fun(student &,int,double);
	fun(s,101,80.5);
	return 0;
}

student::student(int n,double s):num(n),score(s){};

void student::change(int n,double s)
{
	num=n;
	score=s;
}

void student::display()
{
	cout<<"num="<<num<<endl;
	cout<<"score="<<score<<endl;
}

void fun(student &t,int n,double s)
{
	t.change(n,s);
	t.display();
}