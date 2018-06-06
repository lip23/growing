#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(a%b==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
