#include <iostream>
using namespace std;

bool p[1000000];

int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		memset(p,1,sizeof(p));
		int max=m>n?m:n;
		int min=m<n?m:n;
		int count=0;
		//int pp=0;
		for(int i=min;i<=max;i++)
		{
			if(p[i]==0)
				continue;
			//pp++;
			int t=i,tc=1;
			while(t!=1)
			{
				tc++;
				if(t%2==0)
					t/=2;
				else
					t=t*3+1;
				if(t>=min&&t<=max)
					p[t]=0;
			}
			count=count>tc?count:tc;
		}
		//cout<<pp<<endl;
		cout<<m<<' '<<n<<' '<<count<<endl;
	}
	return 0;
}