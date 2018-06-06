#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void matrixchain(int,int**,int**,int*);
void traceback(int **,int,int);
void Traceback(int,int,int **);
void show(int**,int);

int main()
{
	ifstream cin("3_1.txt");
	char p;
	do{
		cout<<"please enter the number of matrixes: ";
		int n;
		cin>>n;
		int *matrix=new int[n+1];
		cout<<"please enter the row and col of every matrix: \n";
		for(int i=0;i<=n;++i)cin>>matrix[i];
		int **r=new int *[n+1];
		int **s=new int *[n+1];
		for(int i=0;i<=n;++i){
			r[i]=new int[n+1];
			s[i]=new int[n+1];
		}
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j){
				s[i][j]=0;
				r[i][j]=0;
			}
		matrixchain(n,r,s,matrix);
		show(r,n);
		cout<<endl<<endl;
		show(s,n);
		cout<<endl;
		traceback(s,1,n);
		cout<<endl<<endl;
		Traceback(1,n,s);
		for(int i=0;i<=n;++i){
			delete []r[i];
			delete []s[i];
		}
		delete []s;
		delete []r;
		delete []matrix;
		cout<<"do you want to enter a new suquence of matrixes ? y=='yes'\n";
		cin>>p;
	}while(p=='y');
	cin.close();
	return 0;
}

void matrixchain(int n,int **res,int **s,int *m)
{
	for(int i=1;i<=n;++i){s[i][i]=res[i][i]=0;}
	for(int k=2;k<=n;++k)
		for(int r=1;r<=n-k+1;++r){
			int j=r+k-1;
			res[r][j]=res[r+1][j]+m[r-1]*m[r]*m[j];
			s[r][j]=r;
			for(int c=r+1;c<j;++c){
				int min=res[r][c]+res[c+1][j]+m[r-1]*m[c]*m[j];
				if(min<res[r][j]){
					res[r][j]=min;
					s[r][j]=c;
				}
			}
		}
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

void show(int **m,int n)
{
	int w=7;
	cout.setf(ios::left);
	cout<<setw(7)<<' ';
	for(int i=1;i<=n;++i)cout<<setw(7)<<i;
	cout<<endl<<endl;
	for(int i=1;i<=n;++i){
		cout<<setw(w)<<i;
		for(int j=i;j<=n;++j)
			cout<<setw(7)<<m[i][j];
		cout<<endl;
		w+=7;
	}
}
