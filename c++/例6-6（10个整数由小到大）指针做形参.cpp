#include <iostream>
using namespace std;
int main()
{
	int a[10];
	cout<<"������ʮ������"<<endl;
	for(int i=0;i<10;i++)
		cin>>a[i];
	int *p=a;
	void sort(int *,int);
	sort(p,10);
	cout<<"��10������С�����˳���ǣ�"<<endl;
	for(i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}


void sort(int *p,int n)
{
	int m;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
		{
			if(*(p+i)>*(p+j))
			{
				m=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=m;
			}
	}
}