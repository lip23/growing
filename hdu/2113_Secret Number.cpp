#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	bool first=true;
	while(cin>>s){
		if(!first)cout<<endl;
		int sum=0;
		for(int k=0;s[k];++k){
			int t=s[k]-48;
			if(t%2==0)sum+=t;
		}
		cout<<sum<<endl;
		first=false;
	}
	return 0;
}
