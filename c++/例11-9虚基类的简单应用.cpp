#include <iostream>
#include <string>
using namespace std;

class person
{
public:
	person(string na,char s,int a):name(na),sex(s),age(a){}
	void pshow();
protected:
	string name;
	char sex;
	int age;
};

void person::pshow()
{
	cout<<"name:"<<name<<endl;
	cout<<"sex:"<<sex<<endl;
	cout<<"age:"<<age<<endl;
}

class teacher:virtual public person
{
public:
	teacher(string na,char s,int a,string t):person(na,s,a),title(t){}
	void tshow();
protected:
	string title;
};

void teacher::tshow()
{
	cout<<"title:"<<title<<endl;
}

class student:virtual public person
{
public:
	student(string na,char s,int a,double sc):person(na,s,a),score(sc){}
	void sshow();
protected:
	double score;
};

void student::sshow()
{
	cout<<"score:"<<score<<endl;
}

class graduate:public student,public teacher
{
public:
	graduate(string na,char s,int a,double sc,string t,int w):student(na,s,a,sc),teacher(na,s,a,t),person(na,s,a)
	{
		wage=w;
	}
	void show();
private:
	int wage;
};

void graduate::show()
{
	pshow();
	tshow();
	sshow();
	cout<<"wage:"<<wage<<endl;
}

int main()
{
	graduate g("mickle",'f',18,99.9,"assistant",1888);
	g.show();
	return 0;
}
		
