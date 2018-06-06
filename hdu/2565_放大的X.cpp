#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			if(i==n/2+1)cout<<setw(i)<<'X'<<endl;
			else if(2*i<n)cout<<setw(i)<<'X'<<setw(n-2*i+1)<<'X'<<endl;
			else cout<<setw(n-i+1)<<'X'<<setw(2*i-n-1)<<'X'<<endl;
		}
		cout<<endl;
	}
	return 0;
}
