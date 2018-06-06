#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		int max=sqrt(1.0*m);
		int t=0;
		for(int k=2;k<=max;k++)
			if(m%k==0)
				t+=k+m/k;
		if(m!=1)
		{
			t++;
			if(max*max==m)
				t-=max;
		}
		cout<<t<<endl;
	}
	return 0;
}
