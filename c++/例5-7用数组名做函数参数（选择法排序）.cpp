
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[10];
	cout<<"��������������10������"<<endl;
	for(int i=0;i<10;i++)
		cin>>a[i];
	void order(int arra[],int);
	order(a,10);
	cout<<setiosflags(ios::left);
	cout<<"��10��������С�����˳���ǣ�"<<endl;
	for(i=0;i<10;i++)
		cout<<setw(5)<<a[i];
	cout<<endl;
	return 0;
}


void order(int arra[],int n)
{
	int k,m,j,i;
	for(j=0;j<n;j++)
	{
		k=j;
		for(i=j;i<n;i++)
		{
			if(arra[i]<arra[k])
				k=i;
		}
		m=arra[j];
		arra[j]=arra[k];
		arra[k]=m;
	}
	
}
