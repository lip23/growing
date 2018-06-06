#include <iostream>
using namespace std;
int k,n;
int main()
{
	cout<<"请输入您要输出的行数和列数："<<endl;
	cin>>k>>n;
	void print();
	print();
	return 0;
}

void print()
{
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
			cout<<'+';
		cout<<endl;
	}
}