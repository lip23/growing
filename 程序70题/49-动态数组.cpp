#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int **a;
	int h,l,i,j;
	cout<<"��������Ҫ�����������������"<<endl;
	cin>>h;
	cout<<"��������Ҫ�����������������"<<endl;
	cin>>l;
	a=new int *[h];
	for(i=0;i<h;i++)
		a[i]=new int[l];
	cout<<setiosflags(ios::left);
	cout<<"�������ǣ�"<<endl;
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
	cout<<"�������ת�������ǣ�"<<endl;
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
