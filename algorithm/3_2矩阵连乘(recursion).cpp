#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int **s;
int mc(int*,int,int);
void traceback(int **,int,int);
void Traceback(int,int,int **);

int main()
{
	ifstream cin("3_1.txt");
	char p;
	do{
		cout<<"please enter the number of matrixes: \n";
		int n;
		cin>>n;
		int *matrix=new int[n+1];
		s=new int *[n+1];
		for(int i=0;i<=n;++i)s[i]=new int[n+1];
		cout<<"please enter the row and col of every matrix: \n";
		for(int i=0;i<=n;++i)cin>>matrix[i];
		cout<<"the best value is :"<<mc(matrix,1,n)<<endl;
		traceback(s,1,n);
		cout<<endl;
		Traceback(1,n,s);
		delete []matrix;
		for(int i=0;i<=n;++i)delete []s[i];
		delete []s;
		cout<<"do you want to enter a new suquence of matrixes ? y=='yes'\n";
		cin>>p;
	}while(p=='y');
	cin.close();
	return 0;
}

int mc(int *m,int l,int r)
{
	if(l==r)return 0;
	int temp=mc(m,l,l)+mc(m,l+1,r)+m[l-1]*m[r]*m[l];
	s[l][r]=l;
	for(int i=l+1;i<r;++i){
		int t=mc(m,l,i)+mc(m,i+1,r)+m[l-1]*m[r]*m[i];
		if(t<temp){temp=t;s[l][r]=i;}
	}
	return temp;
}

void traceback(int **m,int l,int r)
{
	if(l==r){
		cout<<'A'<<l;
		return;
	}
	cout<<'(';
	traceback(m,l,m[l][r]);
	traceback(m,m[l][r]+1,r);
	cout<<')';
}

void Traceback(int i,int j,int **s)
{
	if(i==j)return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A "<<i<<','<<s[i][j];
	cout<<" and A "<<s[i][j]+1<<','<<j<<endl;
}
