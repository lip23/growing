//编写具有如下原型的函数：bool f(long x);  其功能为：若整数x仅由偶数字（0、2、4、6、8）
//组成时（如x=26480），函数返回true，否则返回false（如当x=22034时）。并编制主函数对它进行调用。
#include <iostream>
#include <string>
using namespace std;
int main()
{
	long n;
	string m;
	bool f(long);
	bool f(string);
	cout<<"请输入一个整数："<<endl;
	cin>>n;
	if(f(n))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	cout<<"请输入一个整数："<<endl;
	cin>>m;
	if(f(m))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}

bool f(long n)
{
	int m=0,k;
	for(;n;)
	{
		k=n%10;
		n=(n-k)/10;
		for(int i=1;i<=9;i+=2)
			if(k==i)
				m++;
	}
	if(m)
		return false;
	else
		return true;
}

bool f(string m)
{
	int k=0;
	for(int i=0;m[i];i++)
		for(int j=1;j<=9;j++)
			if(m[i]==j+48)
				k++;
	if(k)
		return false;
	else
		return true;
}





