#include <iostream>
using namespace std;
int main()
{
	cout<<"�������10����������ת��Ϊ�������ݡ���������������ֻʹ�û�ֵ��ĸ��"<<endl;
	cout<<"M��D��C��L��X��V��I���ֱ�������ʾ1000��500��100��50��10��5��1��"<<endl;
	cout<<"������һ��������"<<endl;
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


