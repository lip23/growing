#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout<<"进10天的温度情况："<<endl<<endl;
	char a[18][10];
	int b[10]={8,11,16,15,13,18,11,9,7,3};
	int i,j;
	for(i=0;i<10;i++)
		cout<<setw(4)<<b[i];
	cout<<endl<<endl;
	for(i=0;i<18;i++)
		for(j=0;j<10;j++)
			a[i][j]=' ';
	
	for(j=0;j<10;j++)
		for(i=0;i<b[j];i++)
			a[17-i][j]='*';
	for(i=0;i<18;i++)
	{
		for(j=0;j<10;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
	return 0;
}