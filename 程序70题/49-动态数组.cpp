#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int **a;
	int h,l,i,j;
	cout<<"请输入您要创建的数组的行数："<<endl;
	cin>>h;
	cout<<"请输入您要创建的数组的列数："<<endl;
	cin>>l;
	a=new int *[h];
	for(i=0;i<h;i++)
		a[i]=new int[l];
	cout<<setiosflags(ios::left);
	cout<<"该数组是："<<endl;
	for(i=0;i<h;i++)
	{
		for(j=0;j<l;j++)
		{
			a[i][j]=rand()%100+10;
			cout<<setw(4)<<a[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"该数组的转置数组是："<<endl;
	int **b;
	b=new int *[l];
	for(i=0;i<l;i++)
		b[i]=new int[h];
	for(i=0;i<l;i++)
	{
		for(j=0;j<h;j++)
		{
			b[i][j]=a[j][i];
			cout<<setw(4)<<b[i][j];
		}
		cout<<endl;
	}
	delete a;
	delete b;
	return 0;
}
