#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--){
		int a[4]={1,1,1,1};
		string key;
		cin>>key;
		for(int i=0;i<key.size();i++){
			char t=key[i];
			if(a[0]&&isdigit(key[i]))a[0]=0;
			else if(a[1]&&islower(key[i]))a[1]=0;
			else if(a[2]&&isupper(key[i]))a[2]=0;
			else if(a[3]&&(t=='~'||t=='!'||t=='@'||t=='#'||t=='$'||t=='%'||t=='^'))a[3]=0;
		}
		if(a[0]+a[1]+a[2]+a[3]<2&&key.size()>7&&key.size()<17)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

