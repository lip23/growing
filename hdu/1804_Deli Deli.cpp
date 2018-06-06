#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	int l,n;
	cin>>l>>n;
	map<string,string> irregular;
	while(l--){
		string t1,t2;
		cin>>t1>>t2;
		irregular[t1]=t2;
	}
	while(n--){
		string temp;
		cin>>temp;
		map<string,string>::iterator iter=irregular.find(temp);
		if(iter!=irregular.end())temp=iter->second;
		else{
			string::reverse_iterator it=temp.rbegin();
			if(*it=='o'||*it=='s'||*it=='x')temp.append("es");
			else if(*it=='y'&&temp.size()>1&&*(it+1)!='a'&&*(it+1)!='e'
				&&*(it+1)!='i'&&*(it+1)!='o'&&*(it+1)!='u'){
				string::iterator i=it.base()-1;
				temp.erase(i);
				temp.append("ies");
			}
			else if(*it=='h'&&temp.size()>1&&(*(it+1)=='c'||*(it+1)=='s'))temp.append("es");
			else temp.append("s");
		}
		cout<<temp<<endl;
	}
	return 0;
}
