#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int temp[10000];
		memset(temp,0,sizeof(temp));
		int total=0;
		int c=0;
		temp[0]=n;
		while(c!=n)
		{
			n+=c;
			temp[total]=n;
			c=0;
			int t=n;
			while(t)
			{
				c=c*10+t%10;
				t/=10;
			}
			total++;
		}
		cout<<total-1<<endl;
		for(int i=0;i<total;i++)
		{
			cout<<temp[i];
			if(i!=total-1)
				cout<<"--->";
		}
		cout<<endl;
	}
	return 0;
}
