// ��дһ����10����������n��Ϊx���������������ĺ�������x��Ϊ2��8��16�ȣ�����������ԭ�ͣ�
//void Chg10Tox(int n, int x);����д�������������е�������֤����ȷ�ԡ�

#include <iostream>
using namespace std;
int main()
{
	cout<<"�ó������ת��36����֮�ڵ�����9֮��ĺ�����Ϊ��д��ĸA-Z"<<endl;
	void chg10tox(int n,int x);
	int n,x;
	cout<<"������һ��������������"<<endl;
	cin>>n;
	cout<<"��������Ҫת���ɵĽ��ƣ�"<<endl;
	cin>>x;
	chg10tox(n,x);
	return 0;
}

void chg10tox(int n,int x)
{
	char p[20];
	int t;
	for(int i=0;n;i++)
	{
		t=n%x;
		n=(n-t)/x;
		if(t>=0&&t<=9)
			p[i]=t+48;
		else
			p[i]=t+65-10;
	}
	for(i=i-1;i>=0;i--)
		cout<<p[i];
	cout<<endl;
}

