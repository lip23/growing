#include <iostream>
using namespace std;

template <class T>

void maxmin(T*a,int m,int n)
{
	int max=0,min=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(a[max]<a[i*n+j])
				max=i*n+j;
			if(a[min]>a[i*n+j])
				min=i*n+j;
		}
	cout<<"max="<<a[max]<<endl;
	cout<<"min="<<a[min]<<endl;
}

int main()
{
	int a[3][4]={{45,3,29,5},{57,8,30,9},{78,67,5,66}};
	maxmin(a[0],3,4);
	char b[3][4]={'a','r','e','w','f','y','s','l','p','i','n','j'};
	maxmin(b[0],3,4);
	return 0;
}