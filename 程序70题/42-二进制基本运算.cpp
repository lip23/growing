#include <iostream>
#include <string>
using namespace std;
int main()
{
	string m,n,p;
	char s;
	int t1,t2,t;
	int chgto10(string);
	string chgto2(int);
	cout<<"����������2��������"<<endl;
	cin>>m;
	cin>>n;
	cout<<"��������Ҫ��������ִ�е����㣺+  -  *  /  "<<endl;
	cin>>s;
	t1=chgto10(m);
	t2=chgto10(n);
	if(s=='+')
		t=t1+t2;
	else if(s=='-')
		t=t1-t2;
	else if(s=='*')
		t=t1*t2;
	else if(s=='/')
		t=t1/t2;
	p=chgto2(t);	
	cout<<p<<endl;
	return 0;
}

int chgto10(string s)
{
	int i,m,n=0;
	for(i=0;s[i];i++)
	{
		m=s[i]-48;
		n=n*2+m;
	}
	return n;
}

string chgto2(int m)
{
	int i;
	string s,s2;
	s="00000000000000";
	s2=s;
	for(i=0;m;i++)
	{
		s[i]=m%2+48;
		m=m/2;
	}
	for(int j=0;j<i;j++)
		s2[j]=s[i-j-1];
	s2[j]='\0';
	return s2;
}

