#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int re;
		if(n==0)
			re=7;
		else if(n==1)
			re=11;
		else
		{
			int t1=7;
			int t2=11;
			for(int i=2;i<=n;i++)
			{
				re=t1+t2;
				re%=3;
				t1=t2;
				t2=re;
			}
		}
		if(re%3==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
