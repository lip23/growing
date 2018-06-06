#include <iostream>
using namespace std;
int main()
{
	int max(int,int,int);
	double max(double,double,double);
	char max(char,char,char);
	int i1,i2,i3,i;
	cout<<"请输入3个整数"<<endl;
	cin>>i1>>i2>>i3;
	i=max(i1,i2,i3);
	cout<<"3个数中最大的数是："<<i<<endl;
	double d1,d2,d3,d;
	cout<<"请输入3个小数"<<endl;
	cin>>d1>>d2>>d3;
	d=max(d1,d2,d3);
	cout<<"3个数中最大的数是："<<d<<endl;
	char c1,c2,c3,c;
	cout<<"请输入3个字符"<<endl;
	cin>>c1>>c2>>c3;
	c=max(c1,c2,c3);
	cout<<"3个字符中最大的是："<<c<<endl;
	return 0;
}


int max(int a,int b,int c)
{
	if(b>a)
		a=b;
	if(c>a)
		a=c;
	return a;
}

double max(double a,double b,double c)
{
	if(b>a)
		a=b;
	if(c>a)
		a=c;
	return a;
}

char max(char a,char b,char c)
{
	if(b>a)
		a=b;
	if(c>a)
		a=c;
	return a;
}