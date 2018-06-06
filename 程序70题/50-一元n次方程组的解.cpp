#include <iostream>
#include <iomanip>
//#include <fstream>
using namespace std;
int main()
{
	int **a;
	int n;
	int ** chuangjian(int);
	void show(int**,int);
	void huajian(int**,int);
	void qiujie(int** ,int);
	cout<<"请输入您要求解的一元n次方程组的未知量个数："<<endl;
	cin>>n;
	cout<<endl;
	cout<<"请按顺序输入您的方程组各参数的系数："<<endl;
	a=chuangjian(n);
	cout<<setiosflags(ios::left);
	cout<<"您输入的方程组转换成增广矩阵的形式是："<<endl;
	show(a,n);
	cout<<"该矩阵化简为最减行列式的形式："<<endl;
	huajian(a,n);
	cout<<endl;
	show(a,n);
	cout<<endl;
	if(a[n-1][n-1]==0)
	{
		cout<<"您输入的方程无解，操作结束！"<<endl;
		exit(1);
	}
	cout<<"该方程组的解为："<<endl;
	qiujie(a,n);
	delete a;
	return 0;
}

void qiujie(int **a,int n)
{
	int *b;
	b=new int[n];
	for(int k=n-1;k>=0;k--)
	{
		for(int j=k+1;j<n;j++)
			a[k][n]=a[k][n]-a[k][j]*b[j];
		b[k]=a[k][n]/a[k][k];
	}
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<"X"<<i+1<<"="<<b[i]<<endl;
	delete b;
}


int ** chuangjian(int n)
{
	//ifstream infile("50.txt",ios::in);
	int **b;
	b=new int*[n];
	for(int i=0;i<n;i++)
		b[i]=new int [n+1];
	for(int j=0;j<n;j++)
		for(i=0;i<n+1;i++)
			cin>>b[j][i];
	return b;
}

void show(int ** a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n+1;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
}

void huajian(int **a,int n)
{
	for(int k=0;k<n-1;k++)
		for(int i=k+1;i<n;i++)
		{
			int t=a[i][k];
			for(int j=k;j<n+1;j++)
				a[i][j]=a[i][j]*a[k][k]-a[k][j]*t;
		}
}

