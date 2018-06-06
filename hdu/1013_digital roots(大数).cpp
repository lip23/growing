#include <iostream>
#include <string>
using namespace std;
int main()
{
	string data;
	cin>>data;
	while(strcmp(data.c_str(),"0")!=0)
	{
		int t=0,i=0;
		while(data[i]!='\0')
		{
			t+=data[i]-48;
			i++;
		}
		while(t>9)
		{
			i=t;
			t=0;
			while(i!=0)
			{
				t+=i%10;
				i/=10;
			}
		}
		cout<<t<<endl;
		cin>>data;
	}
	return 0;
}
