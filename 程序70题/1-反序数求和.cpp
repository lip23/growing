#include <iostream>
using namespace std;
int main()
{
	cout<<"������һ��������"<<endl<<endl;
	int n;
	int a,b;
	int m=10;
	int c=0;
	cin>>n;
	cout<<endl;
	for(a=n;a!=0;)
	{
		b=a%10;
		a=(a-b)/10;
		c=c*m+b;
	}
	cout<<"�����ķ������ǣ�"<<endl<<endl<<c<<endl<<endl;
	int p;
	p=n+c;
	cout<<"��������ԭ���ĺ��ǣ�"<<p<<endl<<endl;
	return 0;
}

