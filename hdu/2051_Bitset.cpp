#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		int bit[10];
		int k=0;
		while(n)
		{
			bit[k]=n%2;
			n/=2;
			k++;
		}
		for(k--;k>=0;k--)
			cout<<bit[k];
		cout<<endl;
	}
	return 0;
}


