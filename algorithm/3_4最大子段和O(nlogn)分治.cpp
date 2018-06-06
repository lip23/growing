#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace std;

void show(vector<int> &);
int maxsum(vector<int> &,int,int,int &,int &);
int max(vector<int> &);
int bi,bj,ti1,tj1,ti2,tj2,ti3,tj3;

int main()
{
	char p;
	do{
		cout<<"please enter the number of the random sequence: ";
		int n;
		cin>>n;
		vector<int> vec;
		for(int i=0;i<n;++i){
			int temp=rand()%100-50;
			vec.push_back(temp);
		}
		cout<<"the sequence is :"; 
		show(vec);
		int m=max(vec);
		cout<<"the besti is :"<<bi<<"  bestj is :"<<bj<<endl;
		cout<<"the max sum is :"<<m<<endl;
		cout<<"do you want to create a new random sequence ? y=='yes  ";
		cin>>p;
	}while(p=='y');
	return 0;
}

int maxsum(vector<int> &v,int l,int r,int &bi,int &bj)
{
	if(l==r-1){//return v[l]>0?v[l]:0;
		if(v[l]>0){bi=bj=l+1;return v[l];}
		return 0;
	}
	int m=(l+r)/2;
	int sum1=maxsum(v,l,m,ti1,tj1);
	int sum2=maxsum(v,m,r,ti2,tj2);
	int temp=0;
	int tsum=0;
	for(int i=m;i<r;++i){
		temp+=v[i];
		if(temp>tsum){tsum=temp;tj3=i+1;}
	}
	int sum3=tsum;
	tsum=temp=0;
	for(int i=m-1;i>=0;--i){
		temp+=v[i];
		if(temp>tsum){ti3=i+1;tsum=temp;}
	}
	sum3+=tsum;
	if(sum1>sum2&&sum1>sum3){bi=ti1;bj=tj1;return sum1;}
	else if(sum2>sum3){bi=ti2;bj=tj2;return sum2;}
	bi=ti3;
	bj=tj3;
	return sum3;	
}

int max(vector<int> &v)
{
	bi=bj=0;
	ti1=tj1=0;
	ti2=tj2=0;
	ti3=tj3=0;
	return maxsum(v,0,v.size(),bi,bj);
}

void show(vector<int> &v)
{
	for(int i=0;i<v.size();++i)
		cout<<setw(5)<<v[i];
	cout<<endl;
}
