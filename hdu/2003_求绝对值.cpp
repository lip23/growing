#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double temp;
	while(cin>>temp){
		temp=abs(temp);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout<<temp<<endl;
	}
	return 0;
}
