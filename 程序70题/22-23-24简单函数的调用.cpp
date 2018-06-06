#include <iostream>
using namespace std;
int main()
{
	void print();
	void print(int);
	void print(int,int);
	print();
	print(6);
	print(6,8);
	return 0;
}

void print()
{
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}

void print(int k)
{
	for(int i=0;i<k;i++)
		cout<<"+++++++++++++++++"<<endl;
}

void print(int k,int n)
{
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
			cout<<'+';
		cout<<endl;
	}
}