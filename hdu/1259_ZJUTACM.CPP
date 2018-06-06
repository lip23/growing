#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int pos[8];
		for(int k=0;k<8;k++)
			pos[k]=k;
		int m;
		cin>>m;
		for(k=0;k<m;k++)
		{
			int a,b,temp;
			cin>>a>>b;
			temp=pos[a];
			pos[a]=pos[b];
			pos[b]=temp;
		}
		for(k=1;k<8;k++)
			if(pos[k]==2)
			{
				cout<<k<<endl;
				break;
			}
	}
	return 0;
}
