#include <iostream>
using namespace std;
int main()
{
	int a,b;
	int *p1,*p2;
	cout<<"请输入连个整数"<<endl;
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
	cout<<"这连个数从大到小的顺序是："<<endl<<*p1<<"  "<<*p2<<endl;
	return 0;
}