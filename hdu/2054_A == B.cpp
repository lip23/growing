#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string a,b;
	while(cin>>a>>b){
		if(a[0]!='+'&&a[0]!='-')a.insert(0,1,'+');
		//cout<<a<<endl;
		int k=1;
		while(a[k]=='0')a.erase(k,1);
		//cout<<a<<endl;
		for(;k<a.size()&&a[k]!='.';++k);
		//cout<<a<<endl;
		for(int i=a.size()-1;i>=k&&(a[i]=='0'||a[i]=='.');--i)a.erase(i,1);
		//cout<<a<<endl;
		if(b[0]!='+'&&b[0]!='-')b.insert(0,1,'+');
		k=1;
		while(b[k]=='0')b.erase(k,1);
		for(;k<b.size()&&b[k]!='.';++k);
		for(int i=b.size()-1;i>=k&&(b[i]=='0'||b[i]=='.');--i)b.erase(i,1);
		//cout<<b<<endl;
		if(a==b)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
