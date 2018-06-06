#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		int data[1000];
		for(int j=0;j<m;j++)
			cin>>data[j];
		for(j=0;j<m-1;j++)
		{
			int min=j;
			for(int k=j+1;k<m;k++)
				if(data[min]>data[k])
					min=k;
			cout<<data[min]<<' ';
			data[min]=data[j];
		}
		cout<<data[m-1]<<endl;
	}
	return 0;
}
		