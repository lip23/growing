#include <iostream>
using namespace std;
int main()
{
	double e=0;
	double a=1;
	int n,i,j;
	cout<<"����ѭ��������"<<endl;
	for(n=2;n<=23;n+=3)//��������ͬ��E
	{
		for(i=1;i<=n;i++)//���ۼ�n����
		{
			for(j=1;j<=i;j++)//ÿ�������õ�j�Ľ׳�
			{
				a=a*j;
			}
			e=e+a;
			a=1;
		}
		cout<<"��n="<<n<<"ʱ"<<"  n!="<<e<<endl;
		e=0;
	}
	cout<<"����ѭ��������"<<endl;
	for(n=2;n<=23;n+=3)
	{
		for(i=1;i<=n;i++)
		{
			a=a*i;
			e=e+a;
		}
		cout<<"��n="<<n<<"ʱ"<<"  n!="<<e<<endl;
		a=1;
		e=0;
	}
	cout<<"һ��ѭ���ķ�����"<<endl;
	for(n=1;n<=23;n++)
	{
		a=a*n;
		e=e+a;
		if(n%3==2)
			cout<<"��n="<<n<<"ʱ"<<"  n!="<<e<<endl;
	}
	return 0;
}

