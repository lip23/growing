#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

char *edge;
int *point;
int **tmax;
int **tmin;
void polygon(int);
void calculate(int,int,int,int,int &,int &);
void show(int **,int n);

int main()
{
	char p;
	do{
		cout<<"please enter the number of edges :";
		int n;
		cin>>n;
		vector<int> vec;
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
		for(int i=1;i<=n;++i){
			tmax[i][i]=point[i];
			tmin[i][i]=point[i];
		}
		polygon(n);
		int max=tmax[1][n];
		vec.push_back(1);
		show(tmin,n);
		show(tmax,n);
		for(int cut=2;cut<=n;++cut){
			cout<<"cut="<<cut<<endl;
			edge[0]=edge[2];
			point[0]=point[1];
			for(int i=1;i<n;++i){
				int j=i%n+1;
				point[i]=point[j];
				j=(i+1)%n+1;
				edge[i+1]=edge[j];
			}
			point[n]=point[0];
			edge[1]=edge[0];
			for(int i=1;i<=n;++i)cout<<point[i]<<' ';
			cout<<endl;
			for(int i=2;i<=n;++i)cout<<edge[i]<<' ';
			cout<<endl;
			for(int i=1;i<=n;++i){
				tmax[i][i]=point[i];
				tmin[i][i]=point[i];
			}
			polygon(n);
			show(tmin,n);
			show(tmax,n);
			if(max<tmax[1][n]){
				max=tmax[1][n];
				vec.clear();
				vec.push_back(cut);
			}
			else if(max==tmax[1][n])
				vec.push_back(cut);
		}
		cout<<"max="<<max<<endl;
		for(int i=0;i<vec.size();++i)cout<<vec[i]<<' ';
		cout<<endl;
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

void polygon(int n)
{
	for(int k=2;k<=n;++k)
		for(int r=1;r<=n-k+1;++r){
			int j=r+k-1;
			int tempmin,tempmax;
			calculate(r,r,r+1,j,tempmin,tempmax);
			for(int c=r+1;c<j;++c){
				int ti,ta;
				calculate(r,c,c+1,j,ti,ta);
				if(ti<tempmin)tempmin=ti;
				if(ta>tempmax)tempmax=ta;
			}
			tmin[r][j]=tempmin;
			tmax[r][j]=tempmax;
		}
}

void calculate(int l1,int r1,int l2,int r2,int &ti,int &ta)
{
	if(edge[l2]=='t'){
		ti=tmin[l1][r1]+tmin[l2][r2];
		ta=tmax[l1][r1]+tmax[l2][r2];
	}
	else{
		int t1=tmin[l1][r1]*tmin[l2][r2];
		int t2=tmax[l1][r1]*tmax[l2][r2];
		int t3=tmax[l1][r1]*tmin[l2][r2];
		int t4=tmin[l1][r1]*tmax[l2][r2];
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