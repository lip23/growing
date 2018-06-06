#include <iostream>
using namespace std;
int main()
{
	int max(int,int);
	int a,b,c,d;
	int m;
	cout<<"请输入4个整数"<<endl;
	cin>>a>>b>>c>>d;
	m=max(max(max(a,b),c),d);
	cout<<"这4个整数中最大的是："<<m<<endl;
	return 0;
}


int max(int a,int b)
{
	int m;
	a>=b?m=a:m=b;
	return m;
}