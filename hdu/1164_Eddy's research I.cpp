#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n){
		bool p=false;
		while(n%2==0){
			if(p)cout<<'*';
			cout<<2;
			p=true;
			n/=2;
		}
		for(int k=3;k<=n;k+=2){
			while(n%k==0){
				if(p)cout<<'*';
				cout<<k;
				p=true;
				n/=k;
			}
		}
	cout<<endl;	
	}
	return 0;
}
