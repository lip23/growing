#include <iostream>
using namespace std;
int max(int,int);

int main()
{
	int a,b,c;
	cout<<"������������"<<endl;
	cin>>a>>b;
	//int max(int,int);
	c=max(a,b);
	cout<<"������ǣ�";
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

