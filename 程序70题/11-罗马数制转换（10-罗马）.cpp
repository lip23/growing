#include <iostream>
#include <string>
using namespace std;
int main()
{
	cout<<"��������������ݻ�Ϊ10����������������������ֻʹ������7����ֵ��ĸ��"<<endl;
	cout<<"M��D��C��L��X��V��I���ֱ�������ʾ1000��500��100��50��10��5��1��"<<endl;
	cout<<"�磬�������ݱ�ʾ10���Ƶ�87��"<<endl;
	string l="LXXXVII";
	int t=0;
	for(int i=0;l[i];i++)
		switch(l[i])
		{
		case'M':t=t+1000;break;
		case'D':t=t+500;break;
		case'C':t=t+100;break;
		case'L':t=t+50;break;
		case'X':t=t+10;break;
		case'V':t=t+5;break;
		case'I':t=t+1;break;
		}
	cout<<"l="<<"LXXXVII"<<endl;
	cout<<"t="<<t<<endl;
	return 0;
}
