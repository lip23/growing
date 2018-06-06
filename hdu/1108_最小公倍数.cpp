#include <iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a>b)
		{
			for(int i=1;i<=b;i++)
				if((a*i)%b==0)
					break;
			cout<<a*i<<endl;
		}
		else
		{
			for(int i=1;i<=a;i++)
				if((b*i)%a==0)
					break;
			cout<<b*i<<endl;
		}
	}
	return 0;
}
