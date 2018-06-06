#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[20];
	a[0]=a[1]=1;
	for(int i=2;i<20;i++)
		a[i]=a[i-1]+a[i-2];
	cout<<setiosflags(ios::left);
	for(int n=0;n<20;n++)
	{
		if(n%5==0)
			cout<<endl;
		cout<<setw(8)<<a[n];
	}
	cout<<endl;
	return 0;
}

