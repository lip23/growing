#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b){
		bool f=false;
		for(int i=a;i<=b;++i){
			int temp=i,re=0;
			while(temp){
				re+=pow(temp%10,3.);
				temp/=10;
			}
			if(re==i){
				if(f)cout<<' ';
				cout<<i;
				if(!f)f=true;
			}
		}
		if(!f)cout<<"no";
		cout<<endl;
	}
	return 0;
}
