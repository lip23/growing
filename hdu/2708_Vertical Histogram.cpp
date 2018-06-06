#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> vec(26,0);
	string word;
	for(int r=0;r<4;r++){
		getline(cin,word);
		for(int i=0;i<word.size();++i)
			if(isalpha(word[i]))++vec[word[i]-65];
	}
	int max=*max_element(vec.begin(),vec.end());
	for(;max>0;max--){
		int p=1;
		for(int i=0;i<26;i++){
			if(vec[i]==0)continue;
			if(vec[i]>=max)cout<<setw(p)<<'*';
			else cout<<setw(p)<<' ';
			p=2;
		}
		cout<<endl;
	}
	int f=1;
	for(int k=0;k<26;k++){
		if(vec[k]==0)continue;
		cout<<setw(f)<<static_cast<char> (65+k);
		f=2;
	}
	cout<<endl;
	return 0;
}
