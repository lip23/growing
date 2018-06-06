#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	getchar();
	while(n--){
		string temp;
		getline(cin,temp);
		int l=temp.size();
		for(l--;l>=0;l--)
			cout<<temp[l];
		cout<<endl;
	}
	return 0;
}
