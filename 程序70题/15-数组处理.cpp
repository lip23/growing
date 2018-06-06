#include <iostream>
using namespace std;
int main()
{
	cout<<"对于整型数组a[10]和b[10]，编制程序完成下列任务:"<<endl;
	cout<<"由用户从键盘为两个数组输入值"<<endl;
	cout<<"求出两个数组的最大元和最小元"<<endl;
	cout<<"把数组a和b中的整数分别从小到大和从大到小排序"<<endl;
	cout<<"把两个有序的数组a和b组成一个长度为20的有序数组c[20]"<<endl<<endl<<endl;
	int max(int a[]);
	int min(int b[]);
	int a[10]={45,65,3,23,57,87,5,54,34,98};
	int b[10]={4,5,7,4,34,32,9,0,78,564};
	int c[20];
	int i;
	cout<<"请输入a[10]中的各元素："<<endl;
	for(i=0;i<10;i++)
		cout<<a[i]<<"  ";
	cout<<endl;
		//cin>>a[i];
	cout<<"请输入b[10]中的各元素："<<endl;
	for(i=0;i<10;i++)
		cout<<b[i]<<"  ";
	cout<<endl;
		//cin>>b[i];
	int maxa,maxb,mina,minb;
	maxa=max(a);
	maxb=max(b);
	mina=min(a);
	minb=min(b);
	cout<<"maxa="<<a[maxa]<<endl;
	cout<<"mina="<<a[mina]<<endl;
	cout<<"maxb="<<b[maxb]<<endl;
	cout<<"minb="<<b[minb]<<endl;
	void bsore(int a[],int);
	void ssore(int a[],int);
	bsore(a,10);
	for(i=0;i<10;i++)
		cout<<a[i]<<"  ";
	cout<<endl;
	ssore(b,10);
	for(i=0;i<10;i++)
		cout<<b[i]<<"  ";
	cout<<endl;
	for(i=0;i<10;i++)
	{
		c[i]=a[i];
		c[10+i]=b[i];
	}
	for(i=0;i<20;i++)
		cout<<c[i]<<"  ";
	cout<<endl;
	ssore(c,20);
	for(i=0;i<20;i++)
		cout<<c[i]<<"  ";
	cout<<endl;
	return 0;
}

int max(int a[])
{
	int i=0;
	int m=0;
	for(i=0;i<10;i++)
	{
		if(a[i]>a[m])
			m=i;
	}
	return m;
}

int min(int a[])
{
	int i,m=0;
	for(i=0;i<10;i++)
		if(a[i]<a[m])
			m=i;
	return m;
}

void bsore(int a[],int n)
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
}

void ssore(int a[],int n)
{
	int m,t;
	for(int i=0;i<n;i++)
	{
		m=i;
		for(int j=i+1;j<n;j++)
			if(a[m]>a[j])
				m=j;
		t=a[i];
		a[i]=a[m];
		a[m]=t;
	}
}


