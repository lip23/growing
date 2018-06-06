#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		string t1,t2;
		cin>>t1>>t2;
		int n=t1.size();
		t1.insert(n/2,t2);
		cout<<t1<<endl;
	}
	return 0;
}
