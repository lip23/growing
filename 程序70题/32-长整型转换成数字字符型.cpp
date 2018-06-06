#include <iostream>
using namespace std;
int main()
{
	unsigned int n;
	void inttoacs(int);
	cin>>n;
	inttoacs(n);
	return 0;
}

void inttoacs(int n)
{
	char a[11];
	for(int i=0;n;i++)
	{
		a[i]=n%10+48;
		n=n/10;
	}
	a[i]='\0';
	for(i=i-1;i>=0;i--)
		cout<<a[i];
	cout<<endl;
}