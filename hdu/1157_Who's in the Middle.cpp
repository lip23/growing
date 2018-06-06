#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> milk;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			milk.push_back(temp);
		}
		int mid=n/2;
		nth_element(milk.begin(),milk.begin()+mid,milk.end());
		cout<<milk[mid]<<endl;
	}
	return 0;
}