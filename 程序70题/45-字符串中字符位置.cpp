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
	cout<<"请输入一个字符窜："<<endl;
	cin>>s;
	cout<<"请输入您要查找的字符:"<<endl;
	cin>>c;
	char * i;
	cout<<"该字符串的地址："<<endl;
	for(int j=0;s[j];j++)
		cout<<(int)&s[j]<<endl;
	i=findplace(s,c);
	cout<<"从前往后查找地址："<<endl;
	cout<<(int)i<<endl;
	i=ffindplace(s,c);
	cout<<"从后往前查找地址："<<endl;
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
	

