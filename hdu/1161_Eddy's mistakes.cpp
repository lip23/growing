#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string data;
	while(getline(cin,data)){
		for(int i=0;i<data.size();i++)cout<<static_cast<char> (tolower(data[i]));
		cout<<endl;
	}
	return 0;
}
