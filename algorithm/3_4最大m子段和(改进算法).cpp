#include <iostream>
#include <algorithm>
using namespace std;

int *seq;
int *b;
//int maxsum1(int,int);
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
		b=new int [n+1];
		//for(int i=0;i!=m+1;++i)b[i]=new int[n+1];
		int maxv=maxsum(m,n);
		//show(m,n);
		cout<<"the optimal value is :";
		cout<<maxv<<endl;
		delete []seq;
		delete []b; 
		cout<<"do you want to continue test :y=='yes': ";
		cin>>p;
	}while(p=='y');
	return 0;
}

/*int maxsum1(int m,int n)
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
}*/

int maxsum(int m,int n)
{
	for(int i=0;i<=n;++i)b[i]=0;
	//b[0]=0;
	//b[1]=seq[1];
	for(int i=1;i<=m;++i){
		int last=b[i-1]+seq[i];
		int temp=last;
		for(int j=i+1;j<=n-m+i;++j){
			cout<<"last="<<last<<endl;
			cout<<"b[j-1]="<<b[j-1]<<endl;
			cout<<"seq[j]="<<seq[j]<<endl;
			
			
			temp=max(last,b[j-1])+seq[j];
			
			
			cout<<"temp="<<temp<<endl;
			
			
			
			cout<<"b[j-2]="<<b[j-2]<<endl;
			cout<<"last="<<last<<endl;
			
			cout<<"j="<<j<<endl;
			cout<<"i="<<i<<endl;
			
			if(j>i+1){
				cout<<"iiiiiiiiiiiiiiii"<<endl;
				b[j-1]=max(b[j-2],last);
			}
				
			else b[j-1]=last;
			cout<<"b[j-1]="<<b[j-1]<<endl;
			last=temp;
			cout<<":::::::::::::::::::::::::::::::::::::::"<<endl;
		}
		int t=n-m+i;
		if(t==i)
			b[t]=temp;
		else b[t]=max(b[t-1],temp);
		for(int k=0;k<=n-m+i;++k)cout<<b[k]<<"  ";
		cout<<endl;
	}
	int sum=b[m];
	for(int i=m+1;i<=n;++i)
		if(b[i]>sum)sum=b[i];
	return sum;
}
