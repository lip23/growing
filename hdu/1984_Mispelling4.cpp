#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string temp;
		int p;
		cin>>p>>temp;
		temp.erase(p-1,1);
		cout<<i<<' '<<temp<<endl;
	}
	return 0;
}
