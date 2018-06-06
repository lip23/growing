#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[4][4]={{2,5,3,6},{-5,-3,4,3},{-5,4,8,-6},{-4,-9,6,9}};
	int b[4][4]={{8,-6,-5,4},{1,4,-5,-6},{0,-9,9,7},{8,7,-7,5}};
	int i,j;
	cout<<"a[4][4]:"<<endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
	cout<<"b[4][4]:"<<endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			cout<<setw(4)<<b[i][j];
		cout<<endl;
	}
	int c[4][4];
	cout<<"c[4][4]=a[4][4]+b[4][4]"<<endl;
	cout<<"c[4][4]:"<<endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			cout<<setw(4)<<c[i][j];
		}
		cout<<endl;
	}
	int d[4][4];
	cout<<"d[4][4]=a[4][4]*b[4][4]"<<endl;
	cout<<"d[4][4]:"<<endl;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			d[i][j]=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
				d[i][j]=a[i][k]*b[k][j]+d[i][j];
			cout<<setw(4)<<d[i][j];
		}
		cout<<endl;
	}
	int e[4][4];
	cout<<"e[4][4]为a[4][4]的转职矩阵"<<endl;
	cout<<"e[4][4]:"<<endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			e[i][j]=a[j][i];
			cout<<setw(4)<<e[i][j];
		}
		cout<<endl;
	}
	return 0;
}
