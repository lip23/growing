#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double temp=0;
	double f(int);
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;
	
	cout.precision(9);
	for(int i=0;i<=9;i++)
	{
		temp+=1/f(i);
		if(i==3)
			cout.setf(ios::fixed);
		cout<<i<<' '<<temp<<endl;
	}
	return 0;
}

double f(int n)
{
	if(n==0||n==1)
		return 1;
	else

		return n*f(n-1);
}
