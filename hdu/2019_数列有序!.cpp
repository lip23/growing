#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	int m,n;
	while(cin>>n>>m,m||n)
	{
		vector<int> data;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			data.push_back(temp);
		}
		data.push_back(m);
		sort(data.begin(),data.end(),less<int>());
		vector<int>::iterator iter=data.begin();
		while(iter!=data.end())
		{
			cout<<*(iter++);
			if(iter!=data.end())
				cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}

	