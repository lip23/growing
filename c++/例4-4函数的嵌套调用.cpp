#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	int m;
	cout<<"请输入4个整数"<<endl;
	cin>>a>>b>>c>>d;
	int max_4(int,int,int,int);
	m=max_4(a,b,c,d);
	cout<<"这四个数中最大数是："<<m<<endl;
	return 0;
}

int max_4(int a,int b,int c,int d)
{
	int m;
	int max(int,int);
	m=max(a,b);
	m=max(m,c);
	m=max(m,d);
	return m;
}


int max(int a,int b)
{
	int m;
	a>=b?m=a:m=b;
	return m;
}