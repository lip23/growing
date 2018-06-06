#include <iostream>
using namespace std;
int main()
{
	int f(int);
	int n,m;
	cin>>n;
	m=f(n);
	cout<<"m="<<m<<endl;
	return 0;
}

int f(int n)
{
	int m;
	if(n==1||n==2)
		m=1;
	else if(n>=3)
		m=f(n-1)+f(n-2);
	return m;
}
