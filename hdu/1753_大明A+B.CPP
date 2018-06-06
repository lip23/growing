#include <iostream>
using namespace std;
int main()
{
	char temp1[402],temp2[402];
	while(cin>>temp1>>temp2)
	{
		for(int i=0;temp1[i]&&temp1[i]!='.';i++);
		int a[401];
		int a2[401];
		memset(a,0,sizeof(a));
		memset(a2,0,sizeof(a2));
		int la=strlen(temp1);
		int la1=i;
		int la2=la-la1-1;
		int k=0;
		for(i--;i>=0;i--,k++)
			a[k]=temp1[i]-48;
		for(i=0;i<la2;i++)
			a2[i]=temp1[la1+1+i]-48;
		for(i=0;temp2[i]&&temp2[i]!='.';i++);
		int b[401];
		int b2[401];
		memset(b,0,sizeof(b));
		memset(b2,0,sizeof(b2));
		int lb=strlen(temp2);
		int lb1=i;
		int lb2=lb-lb1-1;
		k=0;
		for(i--;i>=0;i--,k++)
			b[k]=temp2[i]-48;
		for(i=0;i<lb2;i++)
			b2[i]=temp2[lb1+1+i]-48;
		int c[401];
		int c2[401];
		memset(c,0,sizeof(c));
		memset(c2,0,sizeof(c2));
		int l1=la1>lb1?la1:lb1;
		int l2=la2>lb2?la2:lb2;
		for(i=l2-1;i>=0;i--)
		{
			c2[i]+=a2[i]+b2[i];
			if(c2[i]>=10&&i!=0)
			{
				c2[i]-=10;
				c2[i-1]++;
			}
		}
		if(c2[0]>=10)
		{
			c2[0]-=10;
			c[0]++;
		}
		for(i=0;i<l1;i++)
		{
			c[i]+=a[i]+b[i];
			if(c[i]>=10)
			{
				c[i]-=10;
				c[i+1]++;
			}
		}
		if(c[l1]!=0)
			cout<<c[l1];
		for(i=l1-1;i>=0;i--)
			cout<<c[i];
		for(;l2>0&&c2[l2-1]==0;l2--);
		int p=false;
		for(i=0;i<l2;i++)
			if(c2[i]!=0)
			{
				cout<<'.';
				p=true;
				break;
			}
		if(p)
			for(i=0;i<l2;i++)
				cout<<c2[i];
		cout<<endl;
	}
	return 0;
}
