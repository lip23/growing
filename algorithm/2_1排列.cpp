#include <iostream>
#include <vector>
using namespace std;

void swap(char &a,char &b)
{
	char temp=a;
	a=b;
	b=temp;
}

void permutation(vector<char> &t,int p)
{
	if(p==t.size()-1){
		for(int i=0;i<t.size();++i)
			cout<<t[i]<<' ';
		cout<<endl;
		return;
	}
	for(int i=p;i<t.size();++i){
		swap(t[i],t[p]);
		permutation(t,p+1);
		swap(t[i],t[p]);
	}
}

int main()
{
	char p;
	do
	{
		cout<<"please enter the number of elements:";
		int n;
		cin>>n;
		cout<<"please enter the elements:";
		vector<char> v;
		for(int i=0;i<n;++i){
			char temp;
			cin>>temp;
			v.push_back(temp);
		}
		permutation(v,0);
		cout<<"do you want to continue: n=='no'?\n";
		cin>>p;	
	}while(p!='n');
	return 0;
} 
