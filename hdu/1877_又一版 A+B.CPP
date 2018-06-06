#include <iostream>
using namespace std;
int main()
{
	int m;
	while(cin>>m,m)
	{
		int a,b;
		cin>>a>>b;
		int data1[33];
		int data2[33];
		memset(data1,0,sizeof(data1));
		memset(data2,0,sizeof(data2));
		for(int k=0;a;k++)
		{
			data1[k]=a%m;
			a/=m;
		}
		for(k=0;b;k++)
		{
			data2[k]=b%m;
			b/=m;
		}
		for(k=0;k<33;k++)
		{
			data1[k]+=data2[k];
			if(data1[k]>=m)
			{
				data1[k]-=m;
				data1[k+1]++;
			}
		}
		for(k=32;data1[k]==0&&k>0;k--);
		for(;k>=0;k--)
			cout<<data1[k];
		cout<<endl;
	}
	return 0;
}


