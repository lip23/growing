#include <iostream>
using namespace std;
template <typename T>
T max(T a,T b,T c)
{
	if(b>a)
		a=b;
	if(c>a)
		a=c;
	return a;
}

int main()
{
	int a,b,c,m;
	cin>>a>>b>>c;
	m=max(a,b,c);
	cout<<m<<endl;
	return 0;
}




