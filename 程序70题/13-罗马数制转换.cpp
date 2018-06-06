#include <iostream>
using namespace std;
int main()
{
	cout<<"将输入的10进制正整数转换为罗马数据。假设罗马数据中只使用基值字母："<<endl;
	cout<<"M、D、C、L、X、V、I，分别用来表示1000、500、100、50、10、5、1。"<<endl;
	cout<<"请输入一个正整数"<<endl;
	int a,j;
	cin>>a;
	int m,d,c,l,x,v,i;

	m=a/1000;
	for(j=0;j<m;j++)
		cout<<'M';
	a=a-1000*m;

	d=a/500;
	for(j=0;j<d;j++)
		cout<<'D';
	a=a-500*d;

	c=a/100;
	for(j=0;j<c;j++)
		cout<<'C';
	a=a-100*c;

	l=a/50;
	for(j=0;j<l;j++)
		cout<<'L';
	a=a-50*l;

	x=a/10;
	for(j=0;j<x;j++)
		cout<<'X';
	a=a-10*x;

	v=a/5;
	for(j=0;j<v;j++)
		cout<<'V';
	a=a-5*v;

	i=a;
	for(j=0;j<i;j++)
		cout<<'I';

	cout<<endl;
	return 0;
}


