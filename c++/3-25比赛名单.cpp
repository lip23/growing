#include <iostream>
using namespace std;
int main()
{
	char a[3];
	char b[2];
	char c[3];
	a[0]='B';
	a[1]='A';
	a[2]='C';
	b[0]='x';
	b[1]='y';
	b[2]='z';
	for(int i=2;i>=0;i--)
		for(int e=0;e<3;e++)
		{
			if(a[i]=='C'&&b[e]!='x'&&b[e]!='z')
			{
				cout<<a[i]<<" "<<b[e]<<endl;
				c[0]=b[e];
			}
			else if(a[i]=='A'&&b[e]!='x'&&b[e]!=c[0])
			{
				cout<<a[i]<<" "<<b[e]<<endl;
				c[1]=b[e];
			}
			else if(a[i]=='B'&&b[e]!=c[0]&&b[e]!=c[1])
				cout<<a[i]<<" "<<b[e]<<endl;
		}
	return 0;
}
	