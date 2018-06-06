#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

char *edge;
int *point;
int **tmax;
int **tmin;
int polygon(int);
void min_max(int,int,int,int,int &,int &);
void show(int **,int n);

int main()
{
	char p;
	do{
		cout<<"please enter the number of edges :";
		int n;
		cin>>n;
		edge=new char[n+1];
		point=new int[n+1];
		tmax=new int *[n+1];
		tmin=new int *[n+1];
		for(int i=0;i<=n;++i){
			tmax[i]=new int[n+1];
			tmin[i]=new int[n+1];
		}
		cout<<"please enter the sequence of edge and point :\n";
		for(int i=1;i<=n;++i)cin>>edge[i]>>point[i];
		int max=polygon(n);
		show(tmin,n);
		show(tmax,n);
		cout<<"max="<<max<<endl;
		for(int i=0;i<=n;++i){
			delete []tmax[i];
			delete []tmin[i];
		}
		delete []tmax;
		delete []tmin;
		delete []edge;
		delete []point;
		cout<<"do you want to create a new polynon ? y=='yes' :\n";
		cin>>p;
	}while(p=='y');
	return 0;
} 

int polygon(int n)
{
	for(int i=1;i<=n;++i)tmax[i][1]=tmin[i][1]=point[i];
	for(int k=2;k<=n;++k)
		for(int r=1;r<=n;++r){
			int tempmin,tempmax;
			min_max(n,r,1,k,tempmin,tempmax);
			for(int c=2;c<k;++c){
				int ti,ta;
				min_max(n,r,c,k,ti,ta);
				if(ti<tempmin)tempmin=ti;
				if(ta>tempmax)tempmax=ta;
			}
			tmin[r][k]=tempmin;
			tmax[r][k]=tempmax;
		}
	int max=tmax[1][n];
	for(int i=2;i<=n;++i)
		if(tmax[i][n]>max)max=tmax[i][n];
	return max;
}

void min_max(int n,int r,int s,int k,int &ti,int &ta)
{
	int l=(r+s-1)%n+1;
	if(edge[l]=='t'){
		ti=tmin[r][s]+tmin[l][k-s];
		ta=tmax[r][s]+tmax[l][k-s];
	}
	else{
		int t1=tmin[r][s]*tmin[l][k-s];
		int t2=tmax[r][s]*tmax[l][k-s];
		int t3=tmax[r][s]*tmin[l][k-s];
		int t4=tmin[r][s]*tmax[l][k-s];
		int t5=t1>t2?t1:t2;
		int t6=t3>t4?t3:t4;
		ta=t5>t6?t5:t6;
		t5=t1<t2?t1:t2;
		t6=t3<t4?t3:t4;
		ti=t5<t6?t5:t6;	
	}
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
