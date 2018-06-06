#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a>168)
		if(b>168)
			if(c>168)
				cout<<"NO CRASH"<<endl;
			else
				cout<<"CRASH "<<c<<endl;
		else
			cout<<"CRASH "<<b<<endl;
	else
		cout<<"CRASH "<<a<<endl;
	return 0;
}