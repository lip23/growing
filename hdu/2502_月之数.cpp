#include <iostream>
using namespace std;

double f(int n,int t)
{
	double count=1;
	int temp=t>n/2?(n-t):t;
	for(int i=0;i<temp;++i)count=count*(n-i)/(i+1);
	//for(int i=2;i<=temp;++i)count/=i;
	//cout<<"t="<<t<<endl;
	//cout<<"count="<<count<<endl;
	if(t==0)return 1;
	return count*(t+1)+f(n,t-1);
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int data;
		cin>>data;
		cout<<static_cast<int> (f(data-1,data-1))<<endl;
	}
	return 0;
}
