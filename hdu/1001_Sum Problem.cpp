#include <iostream>
using namespace std;
int main()
{
    int n;
	while(cin>>n)
		cout<<(n%2==0?n/2*(n+1):(n+1)/2*n)<<endl<<endl;
    return 0;
}