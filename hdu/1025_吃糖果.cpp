#include <iostream>
using namespace std;
int main()
{
	int m;
	cin>>m;
	for(int k=0;k<m;k++)
	{
		int n;
		cin>>n;
		void f(int);
		f(n);	
	}
	return 0;
}

void f(int n)
{
	int * sugar=new int[n];
	int temp=0;
	double total=0;
	for(int i=0;i<n;i++)
	{
		cin>>sugar[i];
		if(sugar[i]<sugar[temp])
			total+=sugar[i];
		else
		{
			if(temp!=i)
				total+=sugar[temp];
			temp=i;
		}
	}
	if(sugar[temp]>total+1)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	delete []sugar;
}