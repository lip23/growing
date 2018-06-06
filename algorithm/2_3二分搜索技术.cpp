#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
int c=0;
int main()
{
	char p;
	do{
		cout<<"please enter the number of rhe random sequence:";
		int n;
		void show(vector<int> v);
		int midsearch(vector<int>,int,int,int);
		cin>>n;
		vector<int> v;
		for(int i=0;i<n;++i)v.push_back(rand()%1000+1);
		cout<<"the original sequence:\n"; 
		show(v);
		sort(v.begin(),v.end());
		cout<<"the sorted sequence:\n";
		show(v);
		char f;
		do{
			cout<<"please input the number searched:  ";
			int n;
			cin>>n;
			int p=midsearch(v,n,0,v.size()-1);
			if(p<0)cout<<"not found\n";
			else cout<<"the position is :"<<p<<endl;
			cout<<"do you want to continue searching? y=='yes\n";
			cin>>f;	
		}while(f=='y');
		cout<<"do you want to create a new sequence ? y='yes'\n";
		cin>>p;	
	}while(p=='y');
	return 0;
}

void show(vector<int> v)
{
	int s=v.size();
	for(int i=0;i<s;++i)cout<<v[i]<<' ';
	cout<<endl;
}

int midsearch(vector<int> v,int p,int l,int h)
{
	if(l>h)return -1;
	int mid=(l+h)/2;
	if(v[mid]==p)return mid;
	if(v[mid]>p)return midsearch(v,p,l,mid-1);
	return midsearch(v,p,mid+1,h); 
}
