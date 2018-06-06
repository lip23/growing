#include <iostream>
#include <string>
using namespace std;

class teacher
{
public:
	teacher(string,int,string);
	void tshow();
private:
	string name;
	int age;
	string title;
};

teacher::teacher(string n,int a,string t)
{
	name=n;
	age=a;
	title=t;
}

void teacher:: tshow()
{
	cout<<"name:"<<name<<endl;
	cout<<"age:"<<age<<endl;
	cout<<"title:"<<title<<endl;
}

class student
{
public:
	student(string,int,double);
	void sshow();
private:
	string namel;
	int age;
	double score;
};


student::student(string n,int a,double s):namel(n),age(a),score(s){}

void student::sshow()
{
	cout<<"name:"<<namel<<endl;
	cout<<"age:"<<age<<endl;
	cout<<"score:"<<score<<endl;
}

class graduate:public student,public teacher
{
public:
	graduate(string name,int age,string title,double score,char sex);
	void show();
private:
	char sex;
};

graduate::graduate(string name,int age,string title,double score,char s):student(name,age,score),teacher(name,age,title)
{
	sex=s;
}

void graduate::show()
{
	tshow();
	sshow();
	cout<<"sex:"<<sex<<endl;
}

int main()
{
	graduate g1("jake",22,"assistant",89.9,'f');
	g1.show();
	return 0;
}







