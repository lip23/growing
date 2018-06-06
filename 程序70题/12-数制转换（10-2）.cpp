#include <iostream>
using namespace std;
int main()
{
	cout<<"将输入的10进制正整数化为2进制数"<<endl;
	cout<<"请输入一个10进制整数："<<endl;
	int n,m[10],p,q;
	cin>>n;
	p=n;
	for(int i=0;p;i++)
	{
		m[i]=p%2;
		p=p/2;
	}
	for(i--;i>=0;i--)
		cout<<m[i];
	cout<<endl;
	return 0;
}
