#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char data[4]="HDU";
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		int col=3*temp;
		for(int c=0;c<col;c++)
		{
			for(int r=0;r<temp;r++)
				cout<<data;
			cout<<endl;
		}
	}
	return 0;
}

