//��дһ����x������������Ϊ10���������������ĺ�������������ԭ�ͣ�void ChgxTo10(char a[], int x);
//����a�зŵ���x�����������ĸ�λ�����ַ�����x��Ϊ2��8��16�ȣ���Ҫ���仯Ϊ10�����������������д�������������е�������֤����ȷ�ԡ�
//��ʾ��ע����a������x�������ĺϷ��ԡ�
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string n;
	int k;
	void chgxto10(string,int);
	cout<<"�ó������ת��36����֮�ڵ�����9֮��ĺ�����Ϊ��д��ĸA-Z"<<endl;
	cout<<"���������Ľ��ƣ�"<<endl;
	cin>>k;
	cout<<"������һ������"<<endl;
	cin>>n;
	chgxto10(n,k);
	return 0;
}

void chgxto10(string n,int k)
{
	int m=1,p,l,t=0;
	l=strlen(n.c_str());
	for(int i=l-1;i>=0;i--)
	{
		if(k>=1&&k<=9)
			p=n[i]-48;
		else
			p=n[i]-55;
		t=t+p*m;
		m=m*k;
	}
	cout<<t<<endl;
}

