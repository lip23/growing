#include <iostream>
using namespace std;
int main()
{
	int a[10];
	cout<<"��������������a�е�10��Ԫ��"<<endl;
	for(int i=0;i<10;i++)
		cin>>a[i];
	int *p;
	p=a;
	int *q=&a[0];
	cout<<"��*(p+i)�������"<<endl;
	for(i=0;i<10;i++)
		cout<<*(p+i)<<"  ";
	cout<<endl<<"��q[i]�������"<<endl;
	for(i=0;i<10;i++)
		cout<<q[i]<<"  ";
	cout<<endl<<"��*(a+i)�������"<<endl;
	for(i=0;i<10;i++)
		cout<<*(a+i)<<"  ";
	cout<<endl;
	return 0;
}

