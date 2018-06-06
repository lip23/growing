#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a,b;
	while(cin>>a>>b){
		if(a>b){
			int t=b;
			b=a;
			a=t;
		}
		int p[2]={0,0};
		int c;
		for(int i=a;i<=b;++i){
			int m=i%2;
			p[m]+=pow(i*1.,m+2);
		}
		cout<<p[0]<<' '<<p[1]<<endl;
	}
	return 0;
}
