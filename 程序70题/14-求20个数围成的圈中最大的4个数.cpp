#include <iostream>
using namespace std;
int main()
{
	cout<<"由20个正整数排成一圈，编一个程序找出连续的四个数，其和是最大的（不小于圈上任何其它连续的四个数之和"<<endl;
	int a[20];
	int i,m,max=0,n;
	cout<<"请输入20个整数："<<endl;
	for(i=0;i<20;i++)
		cin>>a[i];
	for(i=0;i<20;i++)
	{
		m=a[i%20]+a[(i+1)%20]+a[(i+2)%20]+a[(i+3)%20];
		if(max<m)
		{
			max=m;
			n=i;
		}
	}
	cout<<"最大和max="<<max<<endl;
	cout<<"4个数分别是："<<endl;
	cout<<a[n%20]<<endl<<a[(n+1)%20]<<endl<<a[(n+2)%20]<<endl<<a[(n+3)%20]<<endl;
	return 0;
}


