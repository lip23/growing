#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cout<<"��������������"<<endl;
	cin>>a>>b>>c;
	void sort(int *,int *,int *);
	sort(&a,&b,&c);
	cout<<"����������С�����˳����"<<endl;
	cout<<a<<"  "<<b<<"  "<<c<<"  "<<endl;
	return 0;
}



void sort(int *p1,int *p2,int *p3)
{
	int temp;
	if(*p1>*p2)
	{
		temp=*p1;
		*p1=*p2;
		*p2=temp;
	}
	if(*p3<*p2)
	{
		if(*p3<*p1)
		{
			temp=*p1;
	     	*p1=*p3;
			*p3=*p2;
			*p2=temp;
		}
		else
		{
			temp=*p3;
			*p3=*p2;
			*p2=temp;
		}
	}
}
