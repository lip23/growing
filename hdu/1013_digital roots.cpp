#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		int temp=0;
		while(n!=0)
		{
			temp+=n%10;
			n/=10;
			if(n==0&&temp>9)
			{
				n=temp;
				temp=0;
			}
		}
		cout<<temp<<endl;
		cin>>n;
	}
	return 0;
}