//��д��������ԭ�͵ĺ�����bool f(long x);  �书��Ϊ��������x����ż���֣�0��2��4��6��8��
//���ʱ����x=26480������������true�����򷵻�false���統x=22034ʱ�����������������������е��á�
#include <iostream>
#include <string>
using namespace std;
int main()
{
	long n;
	string m;
	bool f(long);
	bool f(string);
	cout<<"������һ��������"<<endl;
	cin>>n;
	if(f(n))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	cout<<"������һ��������"<<endl;
	cin>>m;
	if(f(m))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}

bool f(long n)
{
	int m=0,k;
	for(;n;)
	{
		k=n%10;
		n=(n-k)/10;
		for(int i=1;i<=9;i+=2)
			if(k==i)
				m++;
	}
	if(m)
		return false;
	else
		return true;
}

bool f(string m)
{
	int k=0;
	for(int i=0;m[i];i++)
		for(int j=1;j<=9;j++)
			if(m[i]==j+48)
				k++;
	if(k)
		return false;
	else
		return true;
}





