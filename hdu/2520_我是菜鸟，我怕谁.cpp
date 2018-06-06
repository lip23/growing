#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int data;
		cin>>data;
		cout<<data*data%10000<<endl;
	}
	return 0;
}
