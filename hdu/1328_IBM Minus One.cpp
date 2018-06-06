#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int t=n;
	while(n--){
		string temp;
		cin>>temp;
		int k=0;
		cout<<"String #"<<t-n<<endl;
		while(temp[k]){
			if(temp[k]=='Z')cout<<'A';
			else cout<<static_cast<char>(temp[k]+1);
			k++;
		}
		cout<<endl<<endl;
	}
	return 0;
}
