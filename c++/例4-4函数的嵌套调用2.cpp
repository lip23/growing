#include <iostream>
using namespace std;
int main()
{
	int max(int,int);
	int a,b,c,d;
	int m;
	cout<<"������4������"<<endl;
	cin>>a>>b>>c>>d;
	m=max(max(max(a,b),c),d);
	cout<<"��4�������������ǣ�"<<m<<endl;
	return 0;
}


int max(int a,int b)
{
	int m;
	a>=b?m=a:m=b;
	return m;
}