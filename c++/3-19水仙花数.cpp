#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a,b,c;
	cout<<setiosflags(ios::left);
	cout<<"��λ����ˮ�ɻ����У�"<<endl;
	for(int i=100;i<=999;i++)
	{
		a=i%10;
		b=(i-a)%100;
		c=(i-a-b)%1000;
		if(a*a*a+b*b*b/1000+c*c*c/1000000==i)
			cout<<setw(5)<<i;
	}
	cout<<endl;
	return 0;
}