#include <iostream>
#include <string>
using namespace std;
int main()
{
	cout<<"��������һ���ַ���s1��������s1�γ��������ַ���s2��s3����ʾ����Ļ�ϡ�"<<endl;
	cout<<"����s2��s1˦����β�������з���ĸ�ַ���õ����ַ�������s3����s2˦����"<<endl;
	cout<<"ǰ�������з���ĸ�ַ����γɵ��ַ��������磬����ִ�к����Ļ��ʾ�����Ϊ:"<<endl;
	cout<<"s1:36 262/x+y*z-a D007 END! %%% 60++=--!"<<endl;
	cout<<"s2=36 262/x+y*z-a D007 END"<<endl;
	cout<<"s3=x+y*z-a D007 END"<<endl;
	string s1,s2,s3;
	cout<<"****************************************************************************"<<endl;
	s1="36 262/x+y*z-a D007 END! %%% 60++=--!";
	int l;
	cout<<"s1= "<<s1<<endl;
	l=strlen(s1.c_str());
	for(int i=l-1;s1[i]<'A'||s1[i]>'z';)
		i--;
	s2=s1;
	s2[i+1]='\0';
	cout<<"s2= ";
	cout<<s2<<endl;
	for(i=0;s1[i]<'A'||s1[i]>'z';)
		i++;
	s3=s2;
	l=strlen(s2.c_str());
	for(int j=0;j<l;j++)
	{
		s3[j]=s2[j+i];
	}
	cout<<"s3= ";
	cout<<s3<<endl;
	return 0;
}
 