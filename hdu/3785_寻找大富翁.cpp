#include <iostream>
using namespace std;
int main()
{
	int m,n;
	while(cin>>m>>n,m||n)
	{
		int *rich=new int[m];
		for(int i=0;i<m;i++)
			cin>>rich[i];
		for(i=0;i<n;i++)
		{
			int max=i;
			for(int j=i+1;j<m;j++)
				if(rich[max]<rich[j])
					max=j;
			cout<<rich[max];
			if(i!=n-1)
				cout<<' ';
			rich[max]=rich[i];
		}
		cout<<endl;
		delete []rich;
	}
	return 0;
}