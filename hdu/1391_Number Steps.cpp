#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==y)
		{
			int pos=x+y;
			if(x%2!=0)
				pos--;
			cout<<pos<<endl;
		}
		else if(x-2==y)
		{
			int pos=2*x-2;
			if(x%2!=0)
				pos--;
			cout<<pos<<endl;
		}
		else
			cout<<"No Number"<<endl;
	}
	return 0;
}