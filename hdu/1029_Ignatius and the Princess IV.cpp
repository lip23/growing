#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int* data=new int[n];
		int* map=new int[n];
		memset(map,0,4*n);
		for(int i=0;i<n;i++)
		{
			cin>>data[i];
			//cout<<map[i]<<endl;
		}
		for(i=0;i<n;i++)
		{
			//cout<<"i="<<i<<endl;
			if(!map[i])
				for(int j=i+1;j<n;j++)
					if(data[i]==data[j])
					{
						//cout<<"kjjjjjjjjjjj"<<endl;
						map[i]++;
						map[j]=1;
					}
			if(map[i]+1>=(n+1)/2)
			{
				//cout<<map[i]<<endl;
				break;
			}
		}
		cout<<data[i]<<endl;
		delete []data;
		delete []map;
	}
	return 0;
}
