#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	string in,out;
	while(cin>>n>>in>>out)
	{
		vector<int> order;
		bool success=true;
		int *flag=new int[n];
		memset(flag,0,n*sizeof(flag));
		for(int i=0,k=0;i<n;i++)
		{
			order.push_back(1);
			if(in[i]==out[k])
			{
				flag[i]=true;
				order.push_back(-1);
				k++;
				for(int t=i-1;t>=0;)
				{
					while(t>=0&&flag[t])
						t--;
					if(t<0)
						break;
					if(in[t]==out[k])
					{
						order.push_back(-1);
						flag[t]=true;
						t--;
						k++;
					}
					else
						break;
				}
			}
		}
		if(order.size()!=2*n)
			success=false;
		if(!success)
			cout<<"No."<<endl;
		else
		{
			cout<<"Yes."<<endl;
			for(i=0;i<order.size();i++)
				if(order[i]==1)
					cout<<"in"<<endl;
				else if(order[i]==-1)
					cout<<"out"<<endl;
		}
		cout<<"FINISH"<<endl;
		delete []flag;
	}
	return 0;
}
