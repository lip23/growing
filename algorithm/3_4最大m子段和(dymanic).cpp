#include <iostream>
using namespace std;

int *seq;
int **b;
int maxsum(int,int);
void show(int,int);

int main()
{
	char p;
	do{
		cout<<"please enter the number of the sequence :";
		int n;
		cin>>n;
		cout<<"please enter the sequence :\n";
		seq=new int[n+1];
		for(int i=1;i!=n+1;++i)cin>>seq[i];
		cout<<"please enter the value m,which you want get the max m subsequence:";
		int m;
		cin>>m;
		b=new int *[m+1];
		for(int i=0;i!=m+1;++i)b[i]=new int[n+1];
		int maxv=maxsum(m,n);
		show(m,n);
		cout<<"the optimal value is :";
		cout<<maxv<<endl;
		for(int i=0;i<=m;++i)delete []b[i];
		delete []b;
		delete []seq;
		cout<<"do you want to continue test :y=='yes': ";
		cin>>p;
	}while(p=='y');
	return 0;
}

int maxsum(int m,int n)
{
	for(int i=0;i!=m+1;++i)b[i][0]=0;//b(i,0)=0;
	for(int i=1;i!=n+1;++i)b[0][i]=0;//b(0,j)=0;
	for(int i=1;i!=m+1;++i){
		b[i][i]=b[i-1][i-1]+seq[i];
		for(int j=i+1;j<=n-m+i;++j){
			b[i][j]=b[i][j-1]+seq[j];
			for(int k=i-1;k<j;++k)
				if(b[i][j]<b[i-1][k]+seq[j])	
					b[i][j]=b[i-1][k]+seq[j];
		}
	}
	int sum=b[m][m];
	for(int j=m+1;j<=n;++j)
		if(sum<b[m][j])sum=b[m][j];
	return sum;
}

void show(int m,int n)
{
	for(int i=0;i!=m+1;++i){
		for(int j=0;j!=n+1;++j)
			cout<<b[i][j]<<"  ";
		cout<<endl;
	}
}
