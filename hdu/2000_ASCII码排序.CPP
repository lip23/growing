#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	char a[3];
	while(cin>>a[0]>>a[1]>>a[2])
	{
		sort(a,a+3,less<char>());
		cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<endl;
	}
	return 0;
}
