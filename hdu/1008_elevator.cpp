#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n>0)
	{
		int * f=new int [n];
		for(int i=0;i<n;i++)
			cin>>f[i];
		int time=f[0]*6;
		for(i=1;i<n;i++)
			f[i]>f[i-1]?time+=(f[i]-f[i-1])*6:time+=(f[i-1]-f[i])*4;
		time+=n*5;
		cout<<time<<endl;
		delete []f;
		cin>>n;
	}
	return 0;
}