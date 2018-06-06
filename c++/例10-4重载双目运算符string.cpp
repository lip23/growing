#include <iostream.h>
#include <string>

class String
{
public:
	String(){p=NULL;}
	String(char *str);
	void display();
	friend int operator >(String &s1,String &s2);
	friend bool operator <(String &s1,String &s2);
	friend bool operator ==(String &s1,String &s2);
private:
	char *p;
};

int main()
{
	String string1("hello"),string2("book"),string3("computer");
	string1.display();
	cout<<endl;
	string2.display();
	cout<<endl;
	cout<<(string1>string2)<<endl;
	cout<<(string1<string2)<<endl;
	cout<<(string1==string2)<<endl;
	void compare(String &s1,String &s2);
	compare(string1,string2);
	compare(string2,string3);
	compare(string1,string3);
	return 0;
}

String::String(char *str)
{
	p=str;
}

void String::display()
{
	cout<<p;
}

int operator >(String &s1,String &s2)
{
	if(strcmp(s1.p,s2.p)>0)
		return 1;
	else
		return 0;
}

bool operator <(String &s1,String &s2)
{
	if(strcmp(s1.p,s2.p)<0)
		return true;
	else
		return false;
}

bool operator ==(String &s1,String &s2)
{
	if(strcmp(s1.p,s2.p)==0)
		return true;
	else
		return false;
}

void compare(String &s1,String &s2)
{
	if(s1>s2)
	{
		s1.display();
		cout<<">";
		s2.display();
		cout<<endl;
	}
	else if(s1<s2)
		{
		s1.display();
		cout<<"<";
		s2.display();
		cout<<endl;
	}
	else if(s1==s2)
		{
		s1.display();
		cout<<"==";
		s2.display();
		cout<<endl;
	}
}
