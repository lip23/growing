#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void show(vector<int> &);
void selectsort(vector<int> &);

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
		selectsort(v);
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

void selectsort(vector<int> &v)
{
	for(int i=0;i<v.size()-1;++i){
		int min=v[i];
		int p=i;
		for(int k=i+1;k<v.size();++k)
			if(v[k]<min){
				p=k;
				min=v[k];
			}
		swap(v[p],v[i]);
	}		
}
