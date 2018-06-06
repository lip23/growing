#include <iostream>
#include <string>
using namespace std;
int main()
{
	string  data;
	while(cin>>data,data!="#"){
		int n=count(data.begin(),data.end(),'1');
		bool parity=false;
		if(n%2==0)parity=true;
		char p=data[data.size()-1];
		data.erase(data.size()-1);
		if((p=='e'&&parity)||(p=='o'&&!parity))data.append(1,'0');
		else data.append(1,'1');
		cout<<data<<endl;
	}
	return 0;
}
