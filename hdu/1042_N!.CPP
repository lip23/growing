#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int re[50000];
		memset(re,0,sizeof(re));
		re[0]=1;
		for(int i=n;i>0;i--)
		{
			for(int j=50000-1;re[j]==0;j--);
			for(;j>=0;j--)
				re[j]*=i;
			for(j=0;j<50000;j++)
				if(re[j]>=10)
				{
					int temp=re[j]/10;
					re[j+1]+=temp;
					re[j]-=temp*10;
				}
		}
		for(int j=50000-1;re[j]==0;j--);
		for(;j>=0;j--)
			cout<<re[j];
		cout<<endl;
	}
	return 0;
}
