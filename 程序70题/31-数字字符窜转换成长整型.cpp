#include <iostream>
using namespace std;
int main()
{
	unsigned int asctoint(char a[]);
	char s[11];
	unsigned int n;
	bool panduan(char a[]);
	cout<<"������һ��0--4294967295֮��������ַ���"<<endl;
	cin>>s;
	while(!panduan(s))
	{
		cout<<"��������ַ���������������"<<endl;
		cin>>s;
	}
	n=asctoint(s);
	cout<<"�������ַ���ת��������n="<<n<<endl;
	return 0;
}

unsigned int asctoint(char a[])
{
	unsigned int m=0,t;
	for(int i=0;a[i];i++)
	{
		t=a[i]-48;
		m=m*10+t;
	}
	return m;
}

bool panduan(char a[])
{
	bool asctodou(char a[]);
	int i=0,p=0;
	for(i;a[i];i++)
		if(a[i]>='0'&&a[i]<='9')
			p;
		else
			p++;
	if(p)
		return false;
	else
		if(asctodou(a))
			return true;
		else
			return false;
}

bool asctodou(char a[])
{
	double m=0,t;
	for(int i=0;a[i];i++)
	{
		t=a[i]-48;
		m=m*10+t;
	}
	if(m>4294967295)
		return false;
	else
		return true;
}
