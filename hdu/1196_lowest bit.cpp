#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		int t=1;
		while(n%2!=1)
		{
			t*=2;
			n/=2;
		}
		cout<<t<<endl;
		cin>>n;
	}
	return 0;
}
