#include <iostream>
using namespace std;

void cht(int &n)
{
	while(n>9)
	{
		int t=0;
		while(n>0)
		{
			t=t+n%10;
			n/=10;
		}
		n=t;
	}
}


int main()
{
	int n;
	while(cin>>n,n)
	{
		int result=1;
		for(int i=0;i<n;i++)
		{
			result*=n;
			cht(result);
		}
		cout<<result<<endl;
	}
	return 0;
}

			