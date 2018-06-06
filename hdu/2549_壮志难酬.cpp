#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		string num;
		int p;
		cin>>num>>p;
		int pos=num.find('.');
		if(pos+p>=num.size())cout<<0<<endl;
		else cout<<num[pos+p]<<endl;
	}
	return 0;
}
