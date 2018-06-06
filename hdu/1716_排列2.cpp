#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	int t=0;
	do
	{
		int a[4];
		int sum=0;
		vector<int> v;
		for(int i=0;i<4;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		if(!sum)
			break;
		if(t)
			cout<<endl;
		for(i=0;i<4;i++)
			if(a[i]!=0)
				for(int j=0;j<4;j++)
					if(i!=j)
						for(int k=0;k<4;k++)
							if(k!=j&&k!=i)
								for(int h=0;h<4;h++)
									if(h!=i&&h!=j&&h!=k)
									{
										int temp=a[i]*1000+a[j]*100+a[k]*10+a[h];
										v.push_back(temp);
									}
		sort(v.begin(),v.end(),less<int>());
		for(i=0;i<v.size();i++)
		{
			if(i&&v[i]/1000!=v[i-1]/1000)
				cout<<endl;
			else if(i&&v[i]!=v[i-1])
				cout<<' ';
			if(i&&v[i]==v[i-1])
				continue;
			cout<<v[i];
			
		}
		cout<<endl;
		t++;
	}while(1);
	return 0;
}
			


