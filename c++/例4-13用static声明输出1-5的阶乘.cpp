#include <iostream>
using namespace std;
int main()
{
	int c;
	int f(int);
	for(int i=1;i<=5;i++)
	{
		c=f(i);
		cout<<i<<"!="<<c<<endl;
	}
	return 0;
}


int f(int i)
{
	static int c;
	if(i==1)
		c=1;
	else
		c=i*c;
	return c;
}
