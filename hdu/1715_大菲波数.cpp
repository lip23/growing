#include <iostream>
#include <string>
using namespace std;
int main()
{
	void f(int);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		f(temp);
	}
	return 0;
}

void f(int n)
{
	if(n==1||n==2)
		cout<<1<<endl;
	else
	{
		int t1[300];
		int t2[300];
		
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
	
		t1[0]=1;
		t2[0]=1;
		for(int i=3;i<=n;i++)
		{
			int re[300];	
			memset(re,0,sizeof(re));
			for(int j1=0;j1<300;j1++)
			{
				re[j1]+=t1[j1]+t2[j1];
				if(re[j1]>=10)
				{
					re[j1]-=10;
					re[j1+1]++;
				}
				t1[j1]=t2[j1];
				t2[j1]=re[j1];
			}
			if(i==n)
			{
				for(int k=299;re[k]==0;k--);
				for(;k>=0;k--)
					cout<<re[k];
				cout<<endl;
			}
		}
		
	}
}


