#include <iostream>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <utility>
using namespace std;
int main()
{
	int n;
	while(cin>>n,n){
		multimap<string,string> match;
		map<string,bool> tag;
		map<string,bool>::iterator iter;
		while(n--){
			string t1,t2;
			cin>>t1>>t2;
			match.insert(make_pair(t1,t2));
			iter=tag.find(t2);
			if(iter==tag.end()||iter->second) tag[t2]=false;
			iter=tag.find(t1);
			if(iter==tag.end()) tag.insert(make_pair(t1,true));	
		}
		int tn=tag.size();
		int count=0;
		string champion;
		for(iter=tag.begin();iter!=tag.end();++iter)
			if(iter->second){
				count++;
				champion=iter->first;	
			}
		if(count==1){
			set<string> opponent;
			queue<string> q;
			q.push(champion);
			while(!q.empty()&&opponent.size()!=tn-1){
				string opt=q.front();
				q.pop();
				multimap<string,string>::iterator lowiter=match.lower_bound(opt);
				multimap<string,string>::iterator uppiter=match.upper_bound(opt);
				while(lowiter!=uppiter){
					if(opponent.count(lowiter->second)==0){
						opponent.insert(lowiter->second);
						q.push(lowiter->second);
					}
					lowiter++;
				}
			}
			if(opponent.size()==tn-1) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else cout<<"No"<<endl;
	}
	return 0;
}
