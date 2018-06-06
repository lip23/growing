#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	string temp;
	while(getline(cin,temp)&&temp!="#"){
		//cout<<temp<<endl;
		map<string,int> m;
		int count=0;
		string::iterator siter=temp.begin();
		while(siter!=temp.end()){
			string data;
			while(siter!=temp.end()&&*siter!=' ')data.append(1,*siter++);
			//cout<<data<<endl;
			if(data[0]&&m.insert(make_pair(data,0)).second)count++;
			if(siter!=temp.end())++siter;
		}
		cout<<count<<endl;
	}
	return 0;
}
