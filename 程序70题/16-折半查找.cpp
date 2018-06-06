#include <iostream>
using namespace std;

int main()
{
	int a[15]={23,5,76,3,2,46,676,87,98,90,7,67,6,545,43};
	int i;
	cout<<"a[15]:"<<endl;
	for(i=0;i<15;i++)
		cout<<a[i]<<"  ";
	cout<<endl;
	for(i=0;i<15;i++)
	{
		int m, t;
		m=i;
		for(int j=i+1;j<15;j++)
			if(a[m]>a[j])
				m=j;
		t=a[m];
		a[m]=a[i];
		a[i]=t;
	}
	cout<<"从大到小排列"<<endl;
	for(i=0;i<15;i++)
		cout<<a[i]<<"  ";
	cout<<endl;
	cout<<"请输入您要查找的数："<<endl;
	int p,q;
	int midsearch(int a[],int,int,int);
	cin>>p;
	int hig=14;
	int low=0;
	q=midsearch(a,hig,low,p)+1;
	if(q)
		cout<<"您要查找的数的位置：i="<<q<<endl;
	else
		cout<<"您要查找的数不在该序列中"<<endl;
	return 0;
}

int  midsearch(int a[],int hig,int low,int k)
{
	int mid;
	mid=(hig+low)/2;
	if(low<=hig)
	{
		if(a[mid]>k)
		{
			hig=mid-1;
			return midsearch(a,hig,low,k);
		}
		else if(a[mid]<k)
		{
			low=mid+1;
			return midsearch(a,hig,low,k);
		}
		else if(a[mid]==k)
			return mid;
	}
	else if(low>hig)
		return -1;
}

