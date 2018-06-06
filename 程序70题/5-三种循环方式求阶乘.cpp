#include <iostream>
using namespace std;
int main()
{
	double e=0;
	double a=1;
	int n,i,j;
	cout<<"三重循环方法："<<endl;
	for(n=2;n<=23;n+=3)//求出多个不同的E
	{
		for(i=1;i<=n;i++)//共累加n个项
		{
			for(j=1;j<=i;j++)//每个项中用到j的阶乘
			{
				a=a*j;
			}
			e=e+a;
			a=1;
		}
		cout<<"当n="<<n<<"时"<<"  n!="<<e<<endl;
		e=0;
	}
	cout<<"二重循环方法："<<endl;
	for(n=2;n<=23;n+=3)
	{
		for(i=1;i<=n;i++)
		{
			a=a*i;
			e=e+a;
		}
		cout<<"当n="<<n<<"时"<<"  n!="<<e<<endl;
		a=1;
		e=0;
	}
	cout<<"一重循环的方法："<<endl;
	for(n=1;n<=23;n++)
	{
		a=a*n;
		e=e+a;
		if(n%3==2)
			cout<<"当n="<<n<<"时"<<"  n!="<<e<<endl;
	}
	return 0;
}

