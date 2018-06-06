#include <iostream>
using namespace std;
int main()
{
	int a[3][3];
	int i,j;
	int m=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cin>>a[i][j];
	}
	for(i=0;i<3;i++)
		m=m+a[i][i];
	int *p;
	p=a;
	cout<<m<<endl;
	return 0;
}
