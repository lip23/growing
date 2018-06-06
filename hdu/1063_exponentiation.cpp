#include <iostream>
using namespace std;
int main()
{
	char temp[7];
	int m;
	while(cin>>temp>>m)
	{
		int p=false;
		for(int i=0;temp[i];i++)
			if(temp[i]=='.')
			{
				p=true;
				break;
			}
		int a[200];
		memset(a,0,sizeof(a));
		int l=strlen(temp);
		//cout<<"i="<<i<<endl;
		//cout<<"l="<<l<<endl;
		int la1=i;
		int la2;
		if(p)
			la2=l-la1-1;
		else
			la2=l-la1;
		int k=0;
		for(i=l-1;i>=0;i--)
			if(temp[i]!='.')
			{
				a[k]=temp[i]-48;
				k++;
			}
		for(int c=0;a[c]==0;c++);
		c*=m;
		int num=0;
		if(p)
			i=l-2;
		else
			i=l-1;
		for(;i>=0;i--)
			num=num*10+a[i];
		//cout<<"num="<<num<<endl;
		for(i=1;i<m;i++)
		{
			for(int k=200-1;a[k]==0;k--);
			for(;k>=0;k--)
				a[k]*=num;
			for(int j=0;j<200;j++)
				if(a[j]>=10)
				{
					int tmp=a[j]/10;
					a[j+1]+=tmp;
					a[j]%=10;
				}
		}
		la2*=m;
		//cout<<"la2="<<la2<<endl;
		for(k=200-1;a[k]==0;k--);
		for(;k>=la2;k--)
			cout<<a[k];
		if(p&&la2>c)
			cout<<'.';
		for(k=la2-1;p&&k>=c;k--)
			cout<<a[k];
		cout<<endl;	
	}
	return 0;
}