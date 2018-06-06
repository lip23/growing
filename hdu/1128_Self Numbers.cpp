#include <iostream>
#include <cstdio>
using namespace std;

bool data[1000001];

int main()
{
	for(int i=1;i<=1000000;i++)
		if(!data[i])
		{
			int k=i;
			while(k<1000001)
			{
				int t=k;
				while(t)
				{
					k=k+t%10;
					t/=10;
				}
				if(k>1000000||data[k])
					break;
				data[k]=true;
			}
		}
	//cout<<"result"<<endl;
	for(i=1;i<1000001;i++)
		if(!data[i])
			printf("%d\n",i);
	return 0;
}


