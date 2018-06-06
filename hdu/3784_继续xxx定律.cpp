#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n,n)
	{
		int *data=new int[n];
		int k=0;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			if(temp%2!=0&&(2*temp-1)%3!=0)
			{
				data[k]=temp;
				k++;
			}
		}
		for(k--;k>=0;k--)
		{
			cout<<data[k];
			if(k)
				cout<<' ';
		}
		cout<<endl;
		delete []data;
	}
	return 0;
}