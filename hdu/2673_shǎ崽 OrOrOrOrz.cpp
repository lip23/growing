#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int* data=new int[n];
		for(int i=0;i<n;i++)
			cin>>data[i];
		for(i=0;i<n/2.0;i++)
		{
			int max=i;
			for(int j=i+1;j<n-i;j++)
				if(data[max]<data[j])
					max=j;
			cout<<data[max];
			if(n%2==0||(n%2!=0&&2*i!=n-1))
				cout<<' ';
			int temp=data[max];
			data[max]=data[i];
			int min=n-1-i;
			for(j=n-2-i;j>=i+1;j--)
				if(data[min]>data[j])
					min=j;
			if(data[min]!=temp)
			{
				cout<<data[min];
				if(n%2!=0||(n%2==0&&2*i!=n-2))
					cout<<' ';
				data[min]=data[n-1-i];
			}
		}
		cout<<endl;
		delete []data;
	}
	return 0;
}
