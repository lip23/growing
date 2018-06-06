#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		vector<double> v;
		for(int j=0;j<m;j++)
		{
			double temp;
			cin>>temp;
			v.push_back(temp);
		}
		nth_element(v.begin(),v.begin()+1,v.end(),greater<double>());
		cout.setf(ios::fixed);
		cout.precision(2);
		cout<<v[0]<<endl;
	}
	return 0;
}