#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int t=0;t<n;t++)
	{
		int num1,num2,count=0;
		cin>>num1>>num2;
		int max=num1>num2?num1:num2;
		int min=num1<num2?num1:num2;
		for(int k=min;k<=max;k++)
		{
			int mx=sqrt((double)k);
			int total=1;
			for(int i=2;i<=mx;i++)
				if(k%i==0)
					total+=i+k/i;
			if(total==k)
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
