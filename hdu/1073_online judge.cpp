#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		string corfile,usefile,cortest,usetest;
		char in;
		string tinput;
		cin.get();
		cin>>tinput;
		cin.get();
		while(1){
			string input;
			while(scanf("%c",&in),in!='\n')input.append(1,in);
			if(input=="END")break;
			input.append(1,'\n');
			corfile.append(input);
		}
		cin>>tinput;
		cin.get();
		while(1){
			string input2;
			while(scanf("%c",&in),in!='\n')input2.append(1,in);
			if(input2=="END")break;
			input2.append(1,'\n');
			usefile.append(input2);
		}
		if(corfile==usefile)cout<<"Accepted\n";
		else{
			istringstream stream(corfile),streamu(usefile);
			string temp;
			while(stream>>temp) cortest.append(temp);
			while(streamu>>temp) usetest.append(temp);
			if(cortest==usetest)cout<<"Presentation Error\n";
			else cout<<"Wrong Answer\n";
		}
	}
	return 0;
}
