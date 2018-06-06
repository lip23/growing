#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
int main()
{
	int t;
	cin>>t;
	cin.get();
	while(t--){
		string data,temp,contract;
		getline(cin,data);
		istringstream stream(data);
		while(stream>>temp)contract.append(1,toupper(temp[0]));
		cout<<contract<<endl;
	}
	return 0;
}
