#include <iostream>
using namespace std;
int main()
{
	cout<<"��������10����������������л�����ͬ�����ĸ���num���Լ���num��������һ�����ĳ��ִ�����࣬�������˼��Ρ�"<<endl;
	int a[10];
	int num=10,i;
	int m,max=0,p=0;
	for(i=0;i<10;i++)
		cin>>a[i];
	for(i=0;i<10;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			if(a[i]==a[j])
			{
				p++;
				if(p>max)
				{
					max=p;
					m=i;
				}
			}

		}
		if(p)
		{
			num--;
			p=0;
		}
	}
	max++;
	cout<<"������ͬ�����ĸ�����"<<num<<endl;
	cout<<"���ִ��������ǣ�"<<a[m]<<endl;
	cout<<"���ֵĴ����ǣ�"<<max<<endl;
	return 0;
}
