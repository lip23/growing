#include <iostream>
using namespace std;
int main()
{
	int a,b,n;
	int f(int,int,int);
	cin>>a>>b>>n;
	while(a+b+n!=0)
	{
		cout<<f(a,b,n)<<endl;
		cin>>a>>b>>n;
	}
	return 0;
}

int f(int a,int b,int n)
{
	if(n==1||n==2)
		return 1;
	else
	{
		int t1=1,t2=1;
		for(int i=2;i<n;i++)
		{
			int t0=t2;
			t2=(a*t2+b*t1)%7;
			t1=t0;
		}
		return t2;
	}
}