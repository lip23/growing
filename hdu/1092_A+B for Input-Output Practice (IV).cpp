#include <iostream>
using namespace std;
int main()
{
	int t;
	while(cin>>t,t){
		int sum=0;
		for(int i=0;i<t;i++){
			int temp;
			cin>>temp;
			sum+=temp;
		}
		cout<<sum<<endl;
	}
	return 0;
}
