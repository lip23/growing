#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
	ifstream in("1982.txt");
	int n;
	in>>n;
	while(n--){
		string data;
		in>>data;
		int c=0;
		string::iterator iter=data.begin();
		while(iter!=data.end()){
			if(isdigit(*iter))c=c*10+*iter-'0';
			else{
				if(c)cout<<static_cast<char> (c+64);
				if(*iter=='#')cout<<' ';
				c=0;
			}
			++iter;
		}
		if(c)cout<<static_cast<char> (c+64);
		cout<<endl;
	}
	in.close();
	return 0;
}
