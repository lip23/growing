#include <iostream>
using namespace std;
int main()
{
	const double pi=3.1415927;
	double d;
	cout.setf(ios::fixed);
	cout.precision(3);
	while(cin>>d)cout<<pi*d*d*d*4/3<<endl;
	return 0;
}
