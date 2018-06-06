#include <iostream>
using namespace std;
int main()
{
	cout<<"请输入一个整数："<<endl<<endl;
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
	cout<<"该数的反序数是："<<endl<<endl<<c<<endl<<endl;
	int p;
	p=n+c;
	cout<<"反序数与原数的和是："<<p<<endl<<endl;
	return 0;
}

