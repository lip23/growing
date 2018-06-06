#include <iostream>
using namespace std;
int main()
{
	int d;
	cin>>d;
	while(d--){
		int n;
		cin>>n;
		int t=n,temp=1;
		int o=0,d=0;
		while(t%2==0){
			t/=2;
			d++;
			temp*=2;
		}
		o=n/temp;
		cout<<o<<' '<<d<<endl;
	}
	return 0;
}
