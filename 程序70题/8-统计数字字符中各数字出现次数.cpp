#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout<<"�����ַ���s������ͳ�Ƴ�s�и������ַ��ĳ��ִ�����������"<<endl;
	string s;
	cin>>s;
	int l,i,a[10];
	l=strlen(s.c_str());
	for(i=0;i<10;i++)
		a[i]=0;
	for(i=0;i<l;i++)
		switch(s[i])
		{
		case'0':a[0]++;break;
		case'1':a[1]++;break;
		case'2':a[2]++;break;
		case'3':a[3]++;break;
		case'4':a[4]++;break;
		case'5':a[5]++;break;
		case'6':a[6]++;break;
		case'7':a[7]++;break;
		case'8':a[8]++;break;
		case'9':a[9]++;break;
		}
	cout<<"0���ֵĴ���:"<<a[0]<<endl;
	cout<<"1���ֵĴ���:"<<a[1]<<endl;
	cout<<"2���ֵĴ���:"<<a[2]<<endl;
	cout<<"3���ֵĴ���:"<<a[3]<<endl;
	cout<<"4���ֵĴ���:"<<a[4]<<endl;
	cout<<"5���ֵĴ���:"<<a[5]<<endl;
	cout<<"6���ֵĴ���:"<<a[6]<<endl;
	cout<<"7���ֵĴ���:"<<a[7]<<endl;
	cout<<"8���ֵĴ���:"<<a[8]<<endl;
	cout<<"9���ֵĴ���:"<<a[9]<<endl;
	return 0;
}