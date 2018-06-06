#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void show(vector<int> &);
void insertsort(vector<int> &);

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
		insertsort(v);
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

void insertsort(vector<int> & v)
{
	for(int i=1;i<v.size();++i)
		for(int j=i;j>0;--j)
			if(v[j]<v[j-1])
				swap(v[j],v[j-1]);
			else break;
}
