#include <iostream>
using namespace std;
int main()
{
	int n,p=1;
	for(n=100000;p;n++)
	{
		int f;//f为转换后的数
		int a=n;
		int m=1,b;
		for(int i=0;a;i++)
		{
			a=a/10;
			m=m*10;
		}
		m=m/10;
		b=n%10;
		a=(n-b)/10;
		f=b*m+a;
		cout<<f<<endl;
		if(f==4*n)
		{
			cout<<"n="<<n<<endl;
			p=0;
		}
	}
	return 0;
}
