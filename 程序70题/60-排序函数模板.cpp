#include <iostream>
using namespace std;
template <class T>

void sort(T *a,int n)
{
	int m,t;
	for(int i=0;i<n;i++)
	{
		m=i;
		for(int j=i+1;j<n;j++)
			if(a[m]<a[j])
				m=j;
		t=a[i];
		a[i]=a[m];
		a[m]=t;
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}


int main()
{
	int a[10]={34,65,67,7,54,39,57,9,0,4};
	double b[10]={5.56,7.6,6.54,43.6,56.56,65.56,4.5,9.9,76,8.6};
	char c[10]={'a','r','g','s','r','y','u','w','i','j'};
	sort(a,10);
	sort(b,10);
	sort(c,10);
	return 0;
}
