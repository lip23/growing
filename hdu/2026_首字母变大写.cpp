#include <iostream>
//#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string text;
	while(getline(cin,text)){
		istringstream stream(text);
		string word;
		bool begin=false;
		while(stream>>word){
			word[0]=toupper(word[0]);
			if(begin)cout<<' ';
			cout<<word;
			begin=true;
		}
		cout<<endl;	
	}
	return 0;
}
