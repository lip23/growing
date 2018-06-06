#include <iostream>
using namespace std;
int main()
{
	double pi=0;
	int m=1;
	double n=1;
	int i=1;
	double t;
	for(;;i++)
	{
		cout<<i<<endl;
		t=2*i-1;
		cout<<t<<endl;
		n=m/t;
		cout<<n<<endl;
		pi+=n;
		cout<<pi<<endl;
		m=-m;
		cout<<m<<endl;
		cout<<'\a';
	}
	pi=pi*4;
	cout<<"π的近似值为:"<<pi<<endl;
	return 0;
}