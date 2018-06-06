#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m,n||m)
	{
		int child[256];
		memset(child,-1,sizeof(child));
		for(int i=0;i<n;i++)
		{
			char d1,d2,d3;
			cin>>d1>>d2>>d3;
			child[d3]=d1;
			child[d2]=d1;
		}
		for(i=0;i<m;i++)
		{
			char r1,r2;
			cin>>r1>>r2;
			int found=false;
			int count=0;
			for(int t1=r1;child[t1]>0;t1=child[t1])
			{
				count++;
				if(child[t1]==r2)
				{
					found=1;
					break;
				}
			}
			if(!found)
			{
				count=0;
				for(int t2=r2;child[t2]>0;t2=child[t2])
				{
					count++;
					if(child[t2]==r1)
					{
						found=2;
						break;
					}
				}
			}
			if(found)
			{
				while(count>1)
				{
					if(count==2)
					{
						cout<<"grand";
						break;
					}
					cout<<"great-";
					count--;
				}
				if(found==1)
					cout<<"parent"<<endl;
				else
					cout<<"child"<<endl;
			}
			else
				cout<<'-'<<endl;
		}
	}
	return 0;
}

