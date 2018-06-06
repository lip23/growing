//编一个返回真假值（布尔值）的函数p，其函数原型为：bool p(int x);
//具有如下功能：若正整数x的各位数字之积等于x*x-10*x-22的话，返回true，否则返false。
//并编主函数，通过调用p，找出1000以内的满足上述关系的所有x。
#include <iostream>
using namespace std;
int main()
{
	int i;
	bool p(int);
	for(i=1;i<=1000;i++)
		if(p(i))
			cout<<i<<endl;
	return 0;
}

bool p(int n)
{
	int a=1;
	int b,m;
	for(m=n;m;)
	{
		b=m%10;
		m=(m-b)/10;
		a=a*b;
	}
	if(n*n-10*n-22==a)
		return true;
	else
		return false;
}

