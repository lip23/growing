#include <iostream>
using namespace std;

class student
{
public:
	student(int,double);
	void change(int,double)const;
	void display()const;
private:
	mutable int num;
	mutable double score;
};

int main()
{
	const student s(101,78.5);
	const student* p;
	p=&s;
	p->display();
	p->change(101,80.5);
	p->display();
	return 0;
}

student::student(int n,double s):num(n),score(s){};

void student::change(int n,double s)const
{
	num=n;
	score=s;
}

void student::display()const
{
	cout<<"num="<<num<<endl;
	cout<<"score="<<score<<endl;
}