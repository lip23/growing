//编一个返回真假值（布尔值）的函数symm，实现如下功能：若正整数n为"回文数"（正读与反读为相同大小的数）的话，返回true，否则返false。
//其函数原型为：bool symm(long n);并编主函数，通过调用symm，求出1000以内所有满足下述特征的m： m和7*m以及3*m*m都是"回文数"，
//如1，11，88，… （ 因为m=1，7*m=7，3*m*m=3； m=11，7*m=77，3*m*m=363； m=88，7*m=616，3*m*m=23232； … ）。
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	bool symm(long);
	int i;
	cout<<setiosflags(ios::left);
	cout<<"法一："<<endl;
	for(i=1;i<=1000;i++)
		if(symm(i)&&symm(7*i)&&symm(3*i*i))
			cout<<setw(5)<<i;
	cout<<endl;
	bool symmt(long);
	cout<<"法二："<<endl;
	for(i=1;i<=1000;i++)
		if(symmt(i)&&symmt(7*i)&&symmt(3*i*i))
			cout<<setw(5)<<i;
	cout<<endl;
	return 0;
}

bool symm(long n)
{
	char a[20];
	int i=0,m,p=0;
	for(;n;i++)
	{
		m=n%10;
		n=(n-m)/10;
		a[i]=m+48;
	}
	a[i]='\0';
	char b[20];
	for(int j=0;j<i;j++)
		b[j]=a[i-j-1];
	b[j]='\0';
	for(int k=0;k<j;k++)
		if(a[k]!=b[k])
			p++;
	if(p)
		return false;
	else
		return true;
}

bool symmt(long n)
{
	int j=10,k=0,m,t;
	for(t=n;t;)
	{
		m=t%10;
		t=(t-m)/10;
		k=k*j+m;
	}
	if(n==k)
		return true;
	else
		return false;
}

