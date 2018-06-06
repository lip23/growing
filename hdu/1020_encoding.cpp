#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int k=0;k<n;k++)
	{
		string s;
		cin>>s;
		int c=1;
		for(int i=0;s[i];i++)
			if(s[i]!=s[i+1])
			{
				if(c!=1)
				{
					cout<<c;
					c=1;
				}
				cout<<s[i];
			}
			else
				c++;
		cout<<endl;
	}
	return 0;
}

