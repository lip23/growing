#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string ip;
	while(getline(cin,ip)){
		bool ri=true;
		int cp=0,cd=0,k=0;
		for(;ip[k];){
			if(!isdigit(ip[k])){ri=false;break;}
			int ad=0,count=0;
			while(ip[k]&&isdigit(ip[k])){++count;ad=ad*10+ip[k++]-'0';}
			if(count>3||ad>255){ri=false;break;}
			++cd;
			if(cp==3)break;
			if(ip[k++]!='.'){ri=false;break;}
			++cp;
		}
		if(ri&&k==ip.size()&&cp==3&&cd==4)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

