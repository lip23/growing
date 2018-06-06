#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
using namespace std;

typedef vector<pair<string,string> >::iterator tp;
string temp;

int main()
{
	ifstream cin("1880.txt");
    string t1,t2;
    vector<pair<string,string> > data;
    while(cin>>t1,t1!="@END@"){
        cin.get();
        getline(cin,t2);
        data.push_back(make_pair(t1,t2));
        t1.erase(0,1);
        t1.erase(t1.size()-1,1);
        data.push_back(make_pair(t2,t1));
    }
    int n;
    cin>>n;
    cin.get();
    while(n--){
        getline(cin,temp);
        string re;
        bool pre(tp b,tp e,const string &s,string &re);
        if(!pre(data.begin(),data.end(),temp,re))cout<<"what?\n";
        else cout<<re<<endl;
    }
    cin.close();
    return 0;
}

bool pre(tp b,tp e,const string &s,string &re)
{
	while(b!=e){
		if(b->first==s){
			re=b->second;
			return true;
		}
		else if(b->second==s){
			re=b->first;
			return true;
		}
		++b;
	}
	return false;
}
