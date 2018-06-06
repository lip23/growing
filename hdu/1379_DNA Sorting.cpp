#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <fstream>
using namespace std;

int countw(string s,int n)
{
	int count=0;
	for(int i=0;i<n-1;++i)
		for(int k=i+1;k<n;++k)
			if(s[i]>s[k])++count;
	return count;
}

int main()
{
	int t;
	ifstream cin("1379.txt");
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		multimap<int,string> dna;
		for(int i=0;i<n;++i){
			string word;
			cin>>word;
			int s=countw(word,m);
			dna.insert(make_pair(s,word));
		}
		multimap<int,string>::iterator iter=dna.begin();
		//cout<<"size="<<dna.size()<<endl;
		while(iter!=dna.end()){
			cout<<iter->second<<endl;
			++iter;
		}
	}
	cin.close();
	return 0;
}
