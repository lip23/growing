#include <iostream>
using namespace std;
int main()
{
	int a,b;
	int *p1,*p2;
	cout<<"��������������"<<endl;
	cin>>a>>b;
	if(a>b)
	{
		p1=&a;
		p2=&b;
	}
	else
	{
		p1=&b;
		p2=&a;
	}
	cout<<"���������Ӵ�С��˳���ǣ�"<<endl<<*p1<<"  "<<*p2<<endl;
	return 0;
}