#include <strstream>
#include <iostream>
using namespace std;

int main()
{
	char c[50];
	strstream strio(c,50,ios::in|ios::out);
	int a[10],b[10];
	cout<<"a[10]:"<<endl;
	for(int i=0;i<10;i++)
	{
		a[i]=rand()%100;
		cout<<a[i]<<" ";
		strio<<a[i]<<" ";
	}
	strio<<ends;
	cout<<endl<<"c:"<<endl;;
	cout<<c<<endl;
	cout<<endl<<"b[10]:"<<endl;
	for(i=0;i<10;i++)
		strio>>b[i];
	int m,t;
	for(i=0;i<10;i++)
	{
		m=i;
		for(int j=i+1;j<10;j++)
		{
			if(b[m]>b[j])
				m=j;
		}
		t=b[i];
		b[i]=b[m];
		b[m]=t;
		cout<<b[i]<<" ";
	}
	ostrstream strout(c,50);
	for(i=0;i<10;i++)
		strout<<b[i]<<" ";
	strio<<ends;
	cout<<endl<<"c:"<<endl;;
	cout<<c<<endl;
	int d[10];
	cout<<endl<<"d[10]:"<<endl;
	istrstream strin(c,50);
	for(i=0;i<10;i++)
	{
		strin>>d[i];
		cout<<d[i]<<" ";
	}
	cout<<endl;
	return 0;
}
