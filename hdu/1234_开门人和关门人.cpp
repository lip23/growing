#include <iostream>
#include <string>
using namespace std;

struct data
{
	char num[16];
	char open[9];
	char close[9];
};

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		data* d=new data[m];
		for(int j=0;j<m;j++)
			cin>>d[j].num>>d[j].open>>d[j].close;
		int early=0;
		int late=0;
		for(int k=1;k<m;k++)
		{
			if(strcmp(d[k].open,d[early].open)<0)
				early=k;
			if(strcmp(d[k].close,d[late].close)>0)
				late=k;
		}
		cout<<d[early].num<<' '<<d[late].num<<endl;
		delete []d;
	}
	return 0;
}
		

