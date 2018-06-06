#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	do
	{
		int r;
		cin>>r;
		int m=n*(n-1)/2;
		int* datan=new int[n];
		int* datam=new int[m];	
		int k=0;
		for(int i=0;i<n;i++)
		{
			cin>>datan[i];
			for(int j=i-1;j>=0;j--)
			{
				datam[k]=datan[i]+datan[j];
				k++;
			}
		}
		delete []datan;
		for(i=0;i<r;i++)
		{
			int max=i;
			for(int j=i+1;j<m;j++)
				if(datam[max]<datam[j])
					max=j;
			cout<<datam[max]<<' ';
			datam[max]=datam[i];
		}
		cout<<endl;
		delete []datam;
	}while(cin>>n);
	return 0;
}


