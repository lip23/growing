//��һ���������ֵ������ֵ���ĺ���p���亯��ԭ��Ϊ��bool p(int x);
//�������¹��ܣ���������x�ĸ�λ����֮������x*x-10*x-22�Ļ�������true������false��
//������������ͨ������p���ҳ�1000���ڵ�����������ϵ������x��
#include <iostream>
using namespace std;
int main()
{
	int i;
	bool p(int);
	for(i=1;i<=1000;i++)
		if(p(i))
			cout<<i<<endl;
	return 0;
}

bool p(int n)
{
	int a=1;
	int b,m;
	for(m=n;m;)
	{
		b=m%10;
		m=(m-b)/10;
		a=a*b;
	}
	if(n*n-10*n-22==a)
		return true;
	else
		return false;
}

