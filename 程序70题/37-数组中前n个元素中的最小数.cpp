#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[30];
	int mymin(int a[],int);
	for(int i=0;i<30;i++)
		a[i]=rand()%100;
	cout<<setiosflags(ios::left);
	for(i=0;i<30;i++)
	{
		cout<<setw(4)<<a[i];
		if((i+1)%15==0)
			cout<<endl;
	}
	int n;
	cin>>n;
	cout<<mymin(a,n)<<endl;
	return 0;
}

int mymin(int a[],int n)
{
	int min(int,int);
	if(n==1)
		return a[0];
	else
		return min(a[n-1],mymin(a,n-1));
}

int min(int a,int b)
{
	return a<b?a:b;
}
