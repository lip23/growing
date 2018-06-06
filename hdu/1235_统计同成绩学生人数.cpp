#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		int * grade=new int[n+1];
		for(int i=0;i<=n;i++)
			cin>>grade[i];
		int c=0;
		for(i=0;i<n;i++)
			if(grade[i]==grade[n])
				c++;
		cout<<c<<endl;
		cin>>n;
	}
	return 0;
}
			

		
