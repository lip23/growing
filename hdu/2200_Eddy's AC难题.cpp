#include <iostream>
using namespace std;

double f(int n,int t)
{
	if(n<2)return 0;
	double count=1;
	int temp=t>n/2?n-t:t;
	for(int i=0;i<temp;++i)count*=(n-i);
	//cout<<"count*="<<count<<endl;
	for(int i=1;i<=temp;++i)count/=i;
	//cout<<"count******="<<count<<endl;
	if(t==2)return count;
	return count*(t-1)+f(n,t-1);
}

int main()
{
	int n;
	while(cin>>n)cout<<static_cast<__int64> (f(n,n))<<endl;
	return 0;
}
