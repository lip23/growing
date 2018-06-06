#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		int p=true;
		vector<int> v;
		while(temp!=1)
			if(temp%2==0)
				temp/=2;
			else
			{
				v.push_back(temp);
				temp=temp*3+1;
			}
		if(v.size()==0)
			cout<<"No number can be output !";
		else
			for(int k=0;k<v.size();k++)
			{
				cout<<v[k];
				if(k!=v.size()-1)
					cout<<' ';
			}
			//if(i!=n-1)
			cout<<endl;
	}
	return 0;
}
