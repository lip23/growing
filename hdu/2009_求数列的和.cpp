#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a,b;
	while(cin>>a>>b){
		double r=a;
		for(int i=1;i<b;++i){
			a=pow(a,0.5);
			r+=a;
		}
		cout.setf(ios::fixed);
		cout.precision(2);
		cout<<r<<endl;
	}
	return 0;
}
