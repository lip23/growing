#include <iostream>
using namespace std;
int max(int,int);

int main()
{
	int a,b,c;
	cout<<"请输入两个数"<<endl;
	cin>>a>>b;
	//int max(int,int);
	c=max(a,b);
	cout<<"最大数是：";
	cout<<c<<endl;
	return 0;
}

int max(int x,int y)
{
	if(x>=y)
		return x;
	else
		return y;
}

