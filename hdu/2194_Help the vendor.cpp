#include <iostream>
#include <map>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k,n||k){
		typedef map<int,int> ty;
		int max=0;
		ty doll;
		while(n--){
			int temp;
			cin>>temp;
			doll[temp]++;
		}
		ty::iterator beg=doll.begin(),end=doll.end();
		while(beg!=end){
			while(beg->second){
				ty::iterator tp=doll.find(beg->first*k);
				if(tp!=end&&tp->second){
					max++;
					--beg->second;
					--tp->second;
				}
				else break;
			}
			++beg;
		}
		cout<<max<<endl;	
	}
	return 0;
}
