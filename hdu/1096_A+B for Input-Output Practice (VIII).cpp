#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--){
		int t;
		cin>>t;
		int sum=0;
		for(int i=0;i<t;i++){
			int temp;
			cin>>temp;
			sum+=temp;
		}
		cout<<sum<<endl;
		if(n)cout<<endl;
	}
	return 0;
}
