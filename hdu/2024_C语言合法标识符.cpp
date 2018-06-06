#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	while(n--){
		string temp;
		getline(cin,temp);
		int k=0;
		if(isalpha(temp[0])||temp[0]=='_')
			for(k=1;isalnum(temp[k])||temp[k]=='_';k++);
		if(k&&!temp[k])cout<<"yes"<<endl;
		else cout<<"no"<<endl; 
	}
	return 0;
}
