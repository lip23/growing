#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--){
		string temp;
		cin.get();
		getline(cin,temp);
		int k=0,count=0;
		while(temp[k])
			if(temp[k++]<0){
				++count;
				++k;
			}
		cout<<count<<endl;
	}
	return 0;
}
