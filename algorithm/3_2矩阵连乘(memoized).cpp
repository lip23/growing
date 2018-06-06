#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int **s;
int **m;
int *p;
int memoizedmatrixchain(int);
int lookup(int,int);
void traceback(int **,int,int);
void Traceback(int,int,int **);

int main()
{
	ifstream cin("3_1.txt");
	char pt;
	do{
		cout<<"please enter the number of matrixes: \n";
		int n;
		cin>>n;
		p=new int[n+1];
		s=new int *[n+1];
		m=new int *[n+1];
		for(int i=0;i<=n;++i){
			s[i]=new int[n+1];
			m[i]=new int[n+1];
		}
		cout<<"please enter the row and col of every matrix: \n";
		for(int i=0;i<=n;++i)cin>>p[i];
		cout<<"the best value is :"<<memoizedmatrixchain(n)<<endl;
		traceback(s,1,n);
		cout<<endl;
		Traceback(1,n,s);
		for(int i=0;i<=n;++i){
			delete []s[i];
			delete []m[i];
		}
		delete []m;
		delete []s;
		delete []p;
		cout<<"do you want to enter a new suquence of matrixes ? y=='yes'\n";
		cin>>pt;
	}while(pt=='y');
	cin.close();
	return 0;
}

int memoizedmatrixchain(int n)
{
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			m[i][j]=0;
	return lookup(1,n);
}

int lookup(int l,int r)
{
	if(m[l][r]>0)return m[l][r];
	if(l==r)return 0;
	int temp=lookup(l,l)+lookup(l+1,r)+p[l-1]*p[r]*p[l];
	s[l][r]=l;
	for(int i=l+1;i<r;++i){
		int t=lookup(l,i)+lookup(i+1,r)+p[l-1]*p[r]*p[i];
		if(t<temp){temp=t;s[l][r]=i;}
	}
	m[l][r]=temp;
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
