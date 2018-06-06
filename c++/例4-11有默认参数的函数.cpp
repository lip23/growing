#include <iostream>
using namespace std;
int main()
{
	int max(int ,int ,int f=0);
	int a,b,c,m;
	cout<<"请输入2个数"<<endl;
	cin>>a>>b;
	m=max(a,b);
	cout<<"最大的数是："<<m<<endl;
	cout<<"请输入3个数"<<endl;
	cin>>a>>b>>c;
	m=max(a,b,c);
	cout<<"最大的数是："<<m<<endl;
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
