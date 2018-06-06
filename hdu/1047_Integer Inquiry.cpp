#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char temp[101];
		int result[200];
		memset(result,0,sizeof(result));
		while(cin>>temp,temp[0]!='0')
		{
			//cout<<"temp="<<temp<<endl;
			int l=strlen(temp)-1;
			for(int k=0;l>=0;l--,k++)
				result[k]+=temp[l]-48;
		}
		for(int k=0;k<110;k++)
			if(result[k]>=10)
			{
				result[k+1]+=result[k]/10;
				result[k]%=10;
			}
		//cout<<"k="<<k<<endl;
		for(k--;result[k]==0&&k>=0;k--);
		//cout<<"k="<<k<<endl;
		if(k==-1)
			cout<<0;
		for(;k>=0;k--)
			cout<<result[k];
		cout<<endl;
		if(i!=n-1)
			cout<<endl;
	}
	return 0;
}

