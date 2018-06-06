#include <iostream>
using namespace std;
int main()
{
	int m,n,p;
	int gy(int,int);
	int gcd(int,int);
	cin>>m>>n;
	p=gy(m,n);
	cout<<p<<endl;
	cin>>m>>n;
	p=gcd(m,n);
	cout<<p<<endl;
	return 0;
}

int gy(int m,int n)
{
	int a,b,i;
	if(m>n)
	{
		a=m;
		b=n;
	}
	else
	{
		a=n;
		b=m;
	}
	for(i=n;i>0;i--)	
		if(n%i==0)
			if(m%i==0)
			{
				return i;
				break;
			}
}

int gcd(int m,int n)
{
	if(m%n==0)
		return n;
	else
		return gcd(n,m%n);
}
