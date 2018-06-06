#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a,b,c,d;
	while(cin>>a>>b>>c>>d){
		cout.setf(ios::fixed);
		cout.precision(2);
		cout<<sqrt((a-c)*(a-c)+(b-d)*(b-d))<<endl;
	}
	return 0;
}
