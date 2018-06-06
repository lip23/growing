#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string temp;
		cin>>temp;
		int la=strlen(temp.c_str());
		int* a=new int[la+1];
		a[0]=0;
		int k=0;
		while(temp[k])
		{
			a[k+1]=temp[k]-48;
			k++;
		}
		cin>>temp;
		int lb=strlen(temp.c_str());
		int* b=new int[lb+1];
		b[0]=0;
		k=0;
		while(temp[k])
		{
			b[k+1]=temp[k]-48;
			k++;
		}
		cout<<"Case "<<i+1<<':'<<endl;
		for(int t=1;t<=la;t++)
			cout<<a[t];
		cout<<" + ";
		for(t=1;t<=lb;t++)
			cout<<b[t];
		cout<<" = ";
		if(la>lb)
		{
			int l=la;
			while(lb>0)
			{
				a[la]+=b[lb];
				if(a[la]>9)
				{
					a[la]-=10;
					a[la-1]++;
				}
				lb--;
				la--;
			}
			if(a[0]!=0)
				cout<<a[0];
			for(int j=1;j<=l;j++)
				cout<<a[j];
		}
		else
		{
			int l=lb;
			while(la>0)
			{
				b[lb]+=a[la];
				if(b[lb]>9)
				{
					b[lb]-=10;
					b[lb-1]++;
				}
				lb--;
				la--;
			}
			if(b[0]!=0)
				cout<<b[0];
			for(int j=1;j<=l;j++)
				cout<<b[j];
		}
		delete []a;
		delete []b;
		cout<<endl;
		if(i!=n-1)
			cout<<endl;
	}
	return 0;
}
