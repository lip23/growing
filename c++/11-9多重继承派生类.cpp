#include <iostream>
#include <string>
using namespace std;

class teacher
{
public:
	teacher(string,int,char,string,string,string);
	void display();
protected:
	string name;
	int age;
	char sex;
	string addr;
	string call;
	string title;
};

teacher::teacher(string na,int a,char s,string ad,string ca,string t)
{
	name=na;
	age=a;
	sex=s;
	addr=ad;
	call=ca;
	title=t;
}

void teacher::display()
{
	cout<<"name:"<<name<<endl;
	cout<<"age:"<<age<<endl;
	cout<<"sex:"<<sex<<endl;
	cout<<"addr:"<<addr<<endl;
	cout<<"call:"<<call<<endl;
	cout<<"title:"<<title<<endl;
}

class cadre
{
public:
	cadre(string na,int a,char s,string ad,string ca,string p);
protected:
	string name;
	int age;
	char sex;
	string addr;
	string call;
	string post;
};

cadre::cadre(string na,int a,char s,string ad,string ca,string p)
{
	name=na;
	age=a;
	sex=s;
	addr=ad;
	call=ca;
	post=p;
}

class teacher_cadre:public teacher,public cadre
{
public:
	teacher_cadre(string na,int a,char s,string ad,string ca,string p,string t,int w);
	void show();
private:
	int wages;
};

teacher_cadre::teacher_cadre(string na,int a,char s,string ad,string ca,string p,string t,int w):
cadre(na,a,s,ad,ca,p),teacher(na,a,s,ad,ca,t),wages(w){}

void teacher_cadre::show()
{
	display();
	cout<<"post:"<<cadre::post<<endl;
	cout<<"wages:"<<wages<<endl;
}

int main()
{
	teacher_cadre tc("innest",26,'f',"spain becalom","88886666","soccer","professor",88888888);
	tc.show();
	return 0;
}



