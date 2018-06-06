#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream in("1113.txt");
	multimap<string,string> dictionary;
	string word;
	while(in>>word,word!="XXXXXX"){
		string sword=word;
		sort(sword.begin(),sword.end());
		dictionary.insert(make_pair(sword,word));
	}
	while(in>>word,word!="XXXXXX"){
		sort(word.begin(),word.end());
		multimap<string,string>::iterator liter=dictionary.lower_bound(word),
										  uiter=dictionary.upper_bound(word);
		if(liter==uiter)cout<<"NOT A VALID WORD"<<endl;
		else{
			vector<string> temp;
			while(liter!=uiter){
				temp.push_back(liter->second);
				++liter;
			}
			sort(temp.begin(),temp.end());
			for(int i=0;i<temp.size();i++)cout<<temp[i]<<endl;
		}
		cout<<"******"<<endl;
	}
	in.close();
	return 0;
}
