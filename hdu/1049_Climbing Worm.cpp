#include <iostream>
using namespace std;
int main()
{
	int n,u,d;
	cin>>n>>u>>d;
	while(n!=0)
	{
		if((n-u)%(u-d)==0)
			cout<<2*((n-u)/(u-d))+1<<endl;
		else
			cout<<2*((n-u)/(u-d)+1)+1<<endl;
		cin>>n>>u>>d;
	}
	return 0;
}