#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char c;
		int a,b;
		cin>>c>>a>>b;
		switch(c)
		{
		case '+':cout<<a+b<<endl;break;
		case '-':cout<<a-b<<endl;break;
		case '*':cout<<a*b<<endl;break;
		case '/':
			{
				if(a%b==0)
					cout<<a/b<<endl;
				else
				{
					cout<<setiosflags(ios::showpoint);
					cout.precision(2);
					cout<<(double)a/b<<endl;
				}
			}
		};
	}
	return 0;
}

