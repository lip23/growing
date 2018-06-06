#include <iostream>
#include <string>
using namespace std;

class teacher
{
public:
	teacher(int,string,char);
	void show();
private:
	int num;
	string name;
	char sex;
};

teacher::teacher(int n,string na,char s)
{
	num=n;
	name=na;
	sex=s;
}

void teacher::show()
{
	cout<<"num:"<<num<<endl;
	cout<<"name:"<<name<<endl;
	cout<<"sex:"<<sex<<endl;
}

class professor;

class birthdate
{
public:
	birthdate(int,int,int);
	void show();
	friend void change(professor &,int,int,int);
private:
	int year;
	int month;
	int day;
};

birthdate::birthdate(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
}

void birthdate::show()
{
	cout<<"birthday:"<<day<<'/'<<month<<'/'<<year<<endl;
}

class professor:public teacher
{
public:
	professor(int,int,int,int,string,char);
	void display();
	friend void change(professor &,int,int,int);
private:
	birthdate birthday;
};

professor::professor(int y,int m,int d,int n,string na,char s):teacher(n,na,s),birthday(y,m,d){}

void professor::display()
{
	show();
	birthday.show();
}

int main()
{
	professor p(1988,9,7,8,"xavi",'f');
	p.display();
	change(p,1986,6,8);
	p.display();
	return 0;
}

void change(professor & p,int y,int m,int d)
{
	p.birthday.year=y;
	p.birthday.month=m;
	p.birthday.day=d;
	cout<<"change:"<<endl;
}

	

