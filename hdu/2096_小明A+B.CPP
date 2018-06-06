#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		a%=100;
		b%=100;
		a+=b;
		a%=100;
		cout<<a<<endl;
	}
	return 0;
}