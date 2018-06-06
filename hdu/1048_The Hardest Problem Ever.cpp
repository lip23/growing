#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string data="VWXYZABCDEFGHIJKLMNOPQRSTU";
	string temp;
	while(getline(cin,temp),temp!="ENDOFINPUT"){
		if(temp=="START"||temp=="END")continue;
		for(int i=0;i<temp.size();i++)
			if(isalpha(temp[i]))cout<<data[temp[i]-65];
			else cout<<temp[i];
		cout<<endl;
	}
	return 0;
}
