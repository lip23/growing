#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	ifstream cin("1880.txt");
	string t1,t2;
	map<string,string> data;
	while(cin>>t1,t1!="@END@"){
		cin.get();
		getline(cin,t2);
		//cout<<"t1="<<t1<<endl;
		//cout<<"t2="<<t2<<endl;
		data.insert(make_pair(t1,t2));
		t1.erase(0,1);
		t1.erase(t1.size()-1,1);
		data.insert(make_pair(t2,t1));
	}
	int n;
	cin>>n;
	cin.get();
	while(n--){
		string temp;
		getline(cin,temp);
		map<string,string>::iterator iter=data.find(temp);
		if(iter==data.end())cout<<"what?\n";
		else cout<<iter->second<<endl;
	}
	cin.close();
	return 0;
}

