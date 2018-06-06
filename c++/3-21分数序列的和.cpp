#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double m=2;
	double n=1;
	double p;
	double t;
	double s=0;
	cout<<setiosflags(ios::left);
	cout<<"前20项的和是"<<endl;
	for(int i=1;i<=20;i++)
	{
		t=m/n;
		cout<<t<<"+";
		s=s+t;
		p=n;
		n=m;
		m=p+n;
	}
	cout<<endl<<"="<<s<<endl;
	return 0;
}

