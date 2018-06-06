#include <iostream>
using namespace std;

int f(int n)
{
	int count=1;
	while(n!=1)
	{
		count++;
		if(n%2==0)
			n/=2;
		else
			n=n*3+1;
	}
	return count;
} 

int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		int count=0;
		int max,min;
		m>n?(max=m,min=n):(max=n,min=m);
		//cout<<max<<endl;
		//cout<<min<<endl;
		for(int i=min;i<=max;i++)
			count=count<f(i)?f(i):count;
		cout<<m<<' '<<n<<' '<<count<<endl;
	}
	return 0;
}
