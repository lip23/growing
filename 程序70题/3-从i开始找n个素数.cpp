#include <iostream>
using namespace std;

int main()
{
	int i,n;
	cout<<"����������i��n���ɳ������i��ʼ���������ҳ�n������"<<endl;
	cout<<"������i=";
	cin>>i;
	cout<<"������n=";
	cin>>n;
	int a,b,c,d=0,m=0;
	for(a=i;m<n;a++)
	{
		for(b=1;b<a;b++)
			for(c=1;c<a;c++)
				if(b*c==a)
					d++;
		if(d==0)
		{
			cout<<a<<endl;
			m++;
		}
		d=0;
	}
	return 0;
}
