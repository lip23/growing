#include <iostream>
using namespace std;
int main()
{
	int a,n,m1,m2;
	int power(int a,int n);
	int power2(int a,int n);
	cin>>a;
	cin>>n;
	m1=power(a,n);
	cout<<m1<<endl;
	m2=power2(a,n);
	cout<<m2<<endl;
	return 0;
}

int power(int a,int n)
{
	if(n==0)
		return 1;
	else if(n==1)
		return a;
	else
		return power(a,n-1)*a;
}

int power2(int a,int n)
{
	int m=1;
	for(int i=0;i<n;i++)
		m=a*m;
	return m;
}
	
