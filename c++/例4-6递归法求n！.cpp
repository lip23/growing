#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"��������Ҫ��Ľ׳���"<<endl;
	cin>>n;
	int f(int);
	int c;
	cout<<"�����Ľ׳��ǣ�"<<endl;
	c=f(n);
	cout<<"="<<c<<endl;
	return 0;
}

int f(int n)
{
	int c;
	if(n==1)
	{
		cout<<1;
		c=1;
	}
	else
	{
		cout<<n<<"*";
		c=n*f(n-1);
	}
	return c;
}

	