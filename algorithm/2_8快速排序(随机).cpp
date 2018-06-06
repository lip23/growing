#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void show(vector<int> &);
void randomsort(vector<int> &v,int l,int r);
int partion(vector<int> &v,int l,int r);
int random(int,int);

int main()
{
	char p;
	do{
		cout<<"please the number of randow sequence :";
		int n;
		cin>>n;
		vector<int> v;
		for(int i=0;i<n;++i){
			v.push_back(rand()%100+1);
		}
		cout<<"the original sequence is:\n";
		show(v);
		randomsort(v,0,v.size());
		cout<<"the sorted sequence is:\n";
		show(v);
		cout<<"do you want to creat a new sequence? y='yes'\n";
		cin>>p;
	}while(p=='y');
	return 0;
}

void show(vector<int> &v)
{
	for(int i=0;i<v.size();++i)cout<<v[i]<<' ';
	cout<<endl;
}

void randomsort(vector<int> &v,int l,int r)
{
	if(l>=r-1)return;
	int m=partion(v,l,r);
	randomsort(v,l,m);
	randomsort(v,m+1,r);
}

int partion(vector<int> &v,int l,int r)
{
	int p=random(l,r);
	swap(v[p],v[l]);
	int i=l;
	int j=r;
	int x=v[l];
	while(true){
		while(v[++i]<x);
		while(v[--j]>x);
		if(i>=j)break;
		swap(v[i],v[j]);	
	}
	//cout<<"l="<<l<<"   v[l]="<<v[l]<<endl;
	swap(v[j],v[l]);
	//show(v);
	return j;
}

int random(int a,int b)
{
	return rand()%(b-a)+a;
}
