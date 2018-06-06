#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--){
		string temp;
		cin>>temp;
		int count=0;
		int k=0;
		while(temp[k])
			if(isdigit(temp[k++]))count++;
		cout<<count<<endl;
	}
	return 0;
}
