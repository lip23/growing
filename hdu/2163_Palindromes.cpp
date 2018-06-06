#include <iostream>
#include <string>
using namespace std;
int main()
{
	int count =1;
	string data;
	while(cin>>data,data!="STOP"){
		string rdata(data.rbegin(),data.rend());
		if(data==rdata)cout<<"#"<<count<<": YES\n";
		else cout<<"#"<<count<<": NO\n";
		count++;
	}
	return 0;
}
