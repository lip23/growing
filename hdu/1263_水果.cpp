#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--){
		int m;
		cin>>m;
		typedef map<string,int> type1;
		type1 fruit;
		typedef map<string,type1> type2;
		type2 province;
		while(m--){
			string fru,pro;
			int count;
			cin>>fru>>pro>>count;
			type2::iterator piter=province.find(pro);
			if(piter!=province.end()){
				type1::iterator fiter=piter->second.find(fru);
				if(fiter!=piter->second.end()) fiter->second+=count;
				else 
					piter->second.insert(make_pair(fru,count));
			}
			else
			{
				type1 f;
				f.insert(make_pair(fru,count));
				province.insert(make_pair(pro,f));
			}
		}
		type2::iterator beg=province.begin();
		type2::iterator end=province.end();
		while(beg!=end){
			cout<<beg->first<<endl;
			type1::iterator b=beg->second.begin();
			type1::iterator e=beg->second.end();
			while(b!=e){
				cout<<"   |----"<<b->first<<'('<<b->second<<')'<<endl;
				++b;
			}
			++beg;
		}
		if(n) cout<<endl;
	}
	return 0;
}
