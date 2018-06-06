#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void show(vector<int>);
void mergesort(vector<int> &,int,int);
void merge(vector<int> &,vector<int> &,int,int);
void copy(vector<int> &,vector<int> &,int,int);

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
		mergesort(v,0,v.size());
		cout<<"the sorted sequence is:\n";
		show(v);
		cout<<"do you want to creat a new sequence? y='yes'\n";
		cin>>p;
	}while(p=='y');
	return 0;
}

void show(vector<int> v)
{
	for(int i=0;i<v.size();++i)cout<<v[i]<<' ';
	cout<<endl;
}

void mergesort(vector<int> &v,int l,int r)
{
	if(l>=r-1)return;
	int m=(l+r)/2;
	mergesort(v,l,m);
	mergesort(v,m,r);
	vector<int> b(v.begin(),v.end());
	merge(v,b,l,r);
	copy(b,v,l,r);
}

void merge(vector<int>& a,vector<int> &b,int l,int r)
{
	int i=l;
	int k=l;
	int m=(l+r)/2;
	int j=m;
	while(i<m&&j<r){
		if(a[i]<a[j])b[k++]=a[i++];
		else b[k++]=a[j++];
	}
	while(i<m)b[k++]=a[i++];
	while(j<r)b[k++]=a[j++];
}

void copy(vector<int> &a,vector<int> &b,int l,int r)
{
	while(l<r)b[l]=a[l++];
}
