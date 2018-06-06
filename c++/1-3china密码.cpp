#include <iostream>
using namespace std;
int main()
{
	char c[5];
	for(int i=0;i<5;i++)
		cin>>c[i];
	for(int n=0;n<5;n++)
	{
		c[n]+=4;
		cout<<c[n]<<"  ";
	}
	cout<<endl;
	return 0;
}
