#include <iostream>
#include <string>
using namespace std;
int  main()
{
	char * findplace(char *,char);
	char * ffindplace(char *,char);
	char * s;
	s=new char;
	char c;
	cout<<"������һ���ַ��ܣ�"<<endl;
	cin>>s;
	cout<<"��������Ҫ���ҵ��ַ�:"<<endl;
	cin>>c;
	char * i;
	cout<<"���ַ����ĵ�ַ��"<<endl;
	for(int j=0;s[j];j++)
		cout<<(int)&s[j]<<endl;
	i=findplace(s,c);
	cout<<"��ǰ������ҵ�ַ��"<<endl;
	cout<<(int)i<<endl;
	i=ffindplace(s,c);
	cout<<"�Ӻ���ǰ���ҵ�ַ��"<<endl;
	cout<<(int)i<<endl;
	return 0;
}

char * findplace(char* str,char c)
{
	for(int i=0;str[i];i++)
		if(str[i]==c)
			return &str[i];
	return NULL;
}

char * ffindplace(char * str,char c)
{
	int n=strlen(str);
	for(int i=n-1;i>=0;i--)
		if(str[i]==c)
			return &str[i];
	return NULL;
}
	

