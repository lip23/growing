#include <iostream>
using namespace std;
int main()
{
	double *p;	
	int n;	 
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		p=new double[32767];
		cout<<"p="<<p<<endl;
		delete p;
	}
	return 0;
}

