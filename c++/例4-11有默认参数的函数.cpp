#include <iostream>
using namespace std;
int main()
{
	int max(int ,int ,int f=0);
	int a,b,c,m;
	cout<<"������2����"<<endl;
	cin>>a>>b;
	m=max(a,b);
	cout<<"�������ǣ�"<<m<<endl;
	cout<<"������3����"<<endl;
	cin>>a>>b>>c;
	m=max(a,b,c);
	cout<<"�������ǣ�"<<m<<endl;
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
