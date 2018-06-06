#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--){
		string word;
		cin>>word;
		map<char,int> total;
		for(int i=0;i<word.size();++i)++total[word[i]];
		cout<<"a:"<<total['a']<<endl;
		cout<<"e:"<<total['e']<<endl;
		cout<<"i:"<<total['i']<<endl;
		cout<<"o:"<<total['o']<<endl;
		cout<<"u:"<<total['u']<<endl;
		if(n)cout<<endl;
	}
	return 0;
}
