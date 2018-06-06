#include <iostream>
using namespace std;
int main()
{
	int m,n;
	int sum(int,int);
	cout<<"求正整数m和n之间的数的累加和"<<endl;
	cout<<"请输入两个正整数m和n，m<=n"<<endl;
	cin>>m>>n;
	while(m>n)
	{
		cout<<"您输入的数字有误，请重新输入："<<endl;
		cin>>m>>n;
	}
	cout<<"sum="<<sum(m,n)<<endl;
	return 0;
}

int sum(int m,int n)
{
	if(m==n)
		return m;
	else
		return sum(m,n-1)+n;
}

