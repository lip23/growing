#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b){
		int p=0;
		while(a--){
			int ti,tj;
			cin>>ti>>tj;
			p^=abs(abs(ti-tj)-1);
		}
		if(!p)cout<<"BAD LUCK!"<<endl;
		else cout<<"I WIN!"<<endl;
	}
	return 0;
}
