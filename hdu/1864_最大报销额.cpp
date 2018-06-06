#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	double q;
	int n;
	while(cin>>q>>n,n)
	{
		vector<double> *v=new vector<double>[n];
		int *flag=new int[n];
		memset(flag,1,4*n);
		for(int i=0;i<n;i++)
		{
			int temp;
			double total=0;
			cin>>temp;
			for(int j=0;j<temp;j++)
			{
				char type;
				double price;
				cin>>type>>price;
				total+=price;
				if(type!='C'||type!='B'||type!='A'||price>600)
					flag[i]=0;
				v[i].push_back(price);
			}
			if(total>1000)
				flag[i]=0;
		}
		vector<double> data;
		for(i=0;i<n;i++)
			if(flag[i])
			{
				vector<double>::iterator iter=v[i].begin();
				while(iter!=v[i].end())
				{
					data.push_back(*iter);
					iter++;
				}
			}
	}
	return 0;
}
				
