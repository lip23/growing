#include <iostream>
using namespace std;
int main()
{
	cout<<"�������10������������Ϊ2������"<<endl;
	cout<<"������һ��10����������"<<endl;
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
