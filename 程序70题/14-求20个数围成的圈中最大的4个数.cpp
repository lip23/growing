#include <iostream>
using namespace std;
int main()
{
	cout<<"��20���������ų�һȦ����һ�������ҳ��������ĸ�������������ģ���С��Ȧ���κ������������ĸ���֮��"<<endl;
	int a[20];
	int i,m,max=0,n;
	cout<<"������20��������"<<endl;
	for(i=0;i<20;i++)
		cin>>a[i];
	for(i=0;i<20;i++)
	{
		m=a[i%20]+a[(i+1)%20]+a[(i+2)%20]+a[(i+3)%20];
		if(max<m)
		{
			max=m;
			n=i;
		}
	}
	cout<<"����max="<<max<<endl;
	cout<<"4�����ֱ��ǣ�"<<endl;
	cout<<a[n%20]<<endl<<a[(n+1)%20]<<endl<<a[(n+2)%20]<<endl<<a[(n+3)%20]<<endl;
	return 0;
}


