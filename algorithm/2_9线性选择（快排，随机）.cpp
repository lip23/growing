#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void show(vector<int> &);
int randomselect(vector<int> &,int,int,int);
int random(int,int);
int randompartion(vector<int> &,int,int);
int partion(vector<int> &,int,int);

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
		char pp;
		do{
			cout<<"please enter the number k (smaller in sorted sequence: ";
			int k;
			cin>>k;
			cout<<"the k smaller value is: "
				<<randomselect(v,--k,0,v.size())<<endl;
			cout<<"do you want to continue to enter another k? y=='yes'\n";
			cin>>pp;
		}while(pp=='y');
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

int randomselect(vector<int> &v,int k,int l,int r)
{
	if(l==r-1)return v[l];
	int m=randompartion(v,l,r);
	if(m-l>k) return randomselect(v,k,l,m);
	return randomselect(v,k-m+l,m,r); 
}

int randompartion(vector<int> &v,int l,int r)
{
	int p=random(l,r);
	swap(v[p],v[l]);
	return partion(v,l,r);
}

int random(int l,int r)
{
	return rand()%(r-l)+l;
}

int partion(vector<int> &v,int l,int r)
{
	int i=l;
	int j=r;
	int x=v[l];
	while(true)
	{
		while(v[++i]<x);
		while(v[--j]>x);
		if(i>=j)break;
		swap(v[i],v[j]);
	}
	swap(v[l],v[j]);
	return j;
}
