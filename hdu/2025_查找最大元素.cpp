#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
int main()
{
	string temp;
	while(cin>>temp){
		string t=temp;
		nth_element(t.begin(),t.begin(),t.end(),greater<char>());
		char c=*t.begin();
		//cout<<"c="<<c<<endl;
		int i=0;
		while(i!=temp.size())
			if(temp[i++]==c){
				temp.insert(i,"(max)");
				i+=5;
			}
		cout<<temp<<endl;	
	}
	return 0;
}
