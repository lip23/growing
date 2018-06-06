#include <iostream>
using namespace std;
int main()
{
	int a,b,k;
	cin>>a>>b>>k;
	while(a+b!=0)
	{
		int t=1;
		for(int i=0;i<k;i++)
			t*=10;
		if(a%t==b%t)
			cout<<-1<<endl;
		else
			cout<<a+b<<endl;
		cin>>a>>b>>k;
	}
	return 0;
}
