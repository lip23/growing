#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			v.push_back(temp);
		}
		sort(v.begin(),v.end(),greater<int>());
		for(i=0;i<m;i++)
		{
			printf("%d",v[i]);
			if(i!=m-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
