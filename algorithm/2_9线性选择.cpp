#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void show(vector<int> &);
int randomselect(vector<int> &,int,int,int);
int random(int,int);
int randompartion(vector<int> &,int,int);
int partion(vector<int> &,int,int);
int partion(vector<int> &,int,int,int);
int select(vector<int> &,int l,int r,int k);


void randomsort(vector<int> &v,int l,int r)
{
	if(l>=r-1)return;
	int m=partion(v,l,r);
	randomsort(v,l,m);
	randomsort(v,m+1,r);
}

void show(vector<int> &v,int l,int r)
{
	for(int i=l;i<r;++i)cout<<setw(5)<<v[i];
	cout<<endl;
}

void sortshow(vector<int>v,int l,int r)
{
	randomsort(v,l,r);
	cout<<"the sort is :\n";
	show(v,l,r);
}

int main()
{
	char p;
	do{
		cout<<"please the number of randow sequence :";
		int n;
		cin>>n;
		vector<int> v;
		for(int i=0;i<n;++i){
			v.push_back(rand()%10000+1);
		}
		//cout<<"the original sequence is:\n";
		//show(v);
		sortshow(v,0,v.size());
		char pp;
		do{
			cout<<"pelease enter the k smallest value :";
			int k;
			cin>>k;
			cout<<"the value is :" ;
			vector<int> vc(v);
			cout<<randomselect(vc,k-1,0,vc.size())<<endl;
			cout<<"///////////////////////////////////"<<endl;
			cout<<"the value is :" ;
			cout<<select(v,0,v.size(),k)<<endl;
			cout<<"do you want to continue enter a new k? y=='yes'\n";
			cin>>pp;
		}while(pp=='y');
		cout<<"do you want to creat a new sequence? y='yes'\n";
		cin>>p;
	}while(p=='y');
	return 0;
}

int select(vector<int> & v,int l,int r,int k)
{
	//cout<<"l="<<l<<"   r="<<r<<"   k="<<k<<endl;
	if(r-l<75) return randomselect(v,k-1,l,r);
	int n=(r-l-5)/5;
	//cout<<"n="<<n<<endl;
	//cout<<"mid values:";
	for(int i=0;i<n;++i){
		randomselect(v,2,l+5*i,l+5*i+5);// randomselect is diferent with select,one's parameter is index while another is position
		swap(v[l+i],v[l+5*i+2]);
		//cout<<setw(5)<<v[l+i];
	}
	//cout<<endl;
	//sortshow(v,0,n);
	int p=select(v,l,l+n,(n+1)/2);//if there are two mid values, select the larger one,(the fourth parameter is position insead index) 
	//cout<<"p="<<p<<endl;
	int m=partion(v,l,r,p);//this partion function wiht four parameters is difrerent with that we learned earlier,p is the value not the index
	//cout<<"m="<<m<<endl;
	//cout<<"display 1:\n";
	//show(v,l,m);
	//cout<<"display 2:\n";
	//show(v,m,r);
	//cout<<"r="<<r<<endl;
	if(m-l>=k)return select(v,l,m,k);
	return select(v,m,r,k-m+l);
}

void show(vector<int> &v)
{
	for(int i=0;i<v.size();++i)cout<<setw(5)<<v[i];
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

int partion(vector<int> &v,int l,int r,int x)
{
	//cout<<"l="<<l<<"r="<<r<<"x="<<x<<endl;
	//cout<<"original data :\n";
	//show(v,l,r);
	int i=l-1,j=r;
	while(true){
		//cout<<"i="<<i<<"j="<<j<<endl;
		while(v[++i]<x&&i<r-1);
		while(v[--j]>x&&j>0);
		if(i>=j)break;
		swap(v[i],v[j]);
	}
	//cout<<"partion :\n";
	//show(v,l,r);
	return j+1;
}
