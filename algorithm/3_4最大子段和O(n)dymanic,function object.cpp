#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace std;

void show(vector<int> &);

struct maxsum
{
	void operator()();
	vector<int> v;
	int bi;
	int bj;
	int sum;
};

int main()
{
	char p;
	do{
		cout<<"please enter the number of the random sequence: ";
		int n;
		cin>>n;
		maxsum vec;
		for(int i=0;i<n;++i){
			int temp=rand()%100-50;
			vec.v.push_back(temp);
		}
		cout<<"the sequence is :"; 
		show(vec.v);
		vec();
		cout<<"the besti is :"<<vec.bi<<"  bestj is :"<<vec.bj<<endl;
		cout<<"the max sum is :"<<vec.sum<<endl;
		cout<<"do you want to create a new random sequence ? y=='yes  ";
		cin>>p;
	}while(p=='y');
	return 0;
}

void show(vector<int> &v)
{
	for(int i=0;i<v.size();++i)
		cout<<setw(5)<<v[i];
	cout<<endl;
}

void maxsum::operator()()
{
	int tempsum=sum=bj=bi=0;
	int ti=0;
	for(int i=0;i<v.size();++i){
		if(tempsum>0)tempsum+=v[i];
		else {
			tempsum=v[i];
			ti=i+1;
		}
		if(tempsum>sum){
			sum=tempsum;
			bj=i+1;
			bi=ti;
		}
	}
}
