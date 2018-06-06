#include <iostream>
using namespace std;
int main()
{
	char a[25],b[25];
	cin>>a>>b;
	while(strcmp(a,"0")!=0&&strcmp(b,"0")!=0)
	{
		int data[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
		int da[26];
		int db[26];
		memset(da,0,sizeof(da));
		memset(db,0,sizeof(db));
		int la=strlen(a)-1;
		int i=0;
		while(la>=0)
		{
			int times=1;
			while(a[la]!=','&&la>=0)
			{
				da[i]+=(a[la]-48)*times;
				times*=10;
				la--;
			}
			la--;
			i++;
		}
		la=i;
		int lb=strlen(b)-1;
		i=0;
		while(lb>=0)
		{
			int times=1;
			while(b[lb]!=','&&lb>=0)
			{
				db[i]+=(b[lb]-48)*times;
				times*=10;
				lb--;
			}
			lb--;
			i++;
		}
		lb=i;
		for(int k=0;k<la;k++)
			cout<<da[k]<<"  ";
		cout<<endl;
		for(k=0;k<lb;k++)
			cout<<db[k]<<"  ";
		cout<<endl;
		if(la>lb)
		{
			for(i=0;i<=lb;i++)
			{
				da[i]+=db[i];
				if(da[i]>=data[i])
				{
					da[i+1]++;
					da[i]-=data[i];
				}
			}
			if(da[la]!=0)
				cout<<da[la]<<',';
			for(la=la-1;la>=0;la--)
			{
				cout<<da[la];
				if(la!=0)
					cout<<',';
			}
			cout<<endl;
		}
		else
		{
			for(i=0;i<=la;i++)
			{
				db[i]+=da[i];
				if(db[i]>=data[i])
				{
					db[i+1]++;
					db[i]-=data[i];
				}
			}
			if(db[lb]!=0)
				cout<<db[lb]<<',';
			for(lb=lb-1;lb>=0;lb--)
			{
				cout<<db[lb];
				if(lb!=0)
					cout<<',';
			}
			cout<<endl;
		}
		cin>>a>>b;
	}
		return 0;
}