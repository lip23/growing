#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace std;

void show(vector<int> &);
int maxsum(vector<int> &,int &,int &);

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
		int bi,bj;
		int max=maxsum(vec,bi,bj);
		cout<<"the besti is :"<<bi<<"  bestj is :"<<bj<<endl;
		cout<<"the max sum is :"<<max<<endl;
		cout<<"do you want to create a new random sequence ? y=='yes  ";
		cin>>p;
	}while(p=='y');
	return 0;
}

int maxsum(vector<int> &v,int &besti,int &bestj)
{
	int sum=0;
	besti=bestj=0;
	for(int i=0;i<v.size();++i){
		int temp=0;
		for(int j=i;j<v.size();++j){
			temp+=v[j];
			if(temp>sum){
				sum=temp;
				besti=i+1;
				bestj=j+1;	
			}
		}
	}	
	return sum;
}

void show(vector<int> &v)
{
	for(int i=0;i<v.size();++i)
		cout<<setw(5)<<v[i];
	cout<<endl;
}
