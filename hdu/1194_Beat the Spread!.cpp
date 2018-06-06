#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int s,d;
		cin>>s>>d;
		if(s-d<0)
			cout<<"impossible"<<endl;
		else
			cout<<(s-d)/2+d<<' '<<(s-d)/2<<endl;
	}
	return 0;
}