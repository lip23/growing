#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(int a,int b)
{
	return abs(a)>abs(b);
}

int main()
{
	int n;
	while(cin>>n,n)
	{
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			v.push_back(temp);
		}
		sort(v.begin(),v.end(),cmp);
		vector<int>::iterator iter=v.begin();
		while(iter!=v.end())
		{
			cout<<*(iter++);
			if(iter!=v.end())
				cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}