#include <iostream>
using namespace std;
int main()
{
	int a[10];
	cout<<"请输入整型数组a中的10个元素"<<endl;
	for(int i=0;i<10;i++)
		cin>>a[i];
	int *p;
	p=a;
	int *q=&a[0];
	cout<<"用*(p+i)法输出："<<endl;
	for(i=0;i<10;i++)
		cout<<*(p+i)<<"  ";
	cout<<endl<<"用q[i]法输出："<<endl;
	for(i=0;i<10;i++)
		cout<<q[i]<<"  ";
	cout<<endl<<"用*(a+i)法输出："<<endl;
	for(i=0;i<10;i++)
		cout<<*(a+i)<<"  ";
	cout<<endl;
	return 0;
}

