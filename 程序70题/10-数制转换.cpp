#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a;
	cout<<"请输入一个2进制数:"<<endl;
	cin>>a;
	int l;
	int j=1,t=0;
	l=strlen(a.c_str());
	for(int i=l-1;i>=0;i--)
	{
		if(a[i]=='1')
			t=t+j;
		j=j*2;
		
	}
	cout<<"该2进制数转换为10进制数："<<t<<endl;
	int p=t;
	string b;
	b=a;
	for(i=0;p;i++)
	{
		b[i]=p%6+48;
		p=p/6;
	}
	cout<<"该10进制数转换为6进制数：";
	for(i=i-1;i>=0;i--)
		cout<<b[i];
	cout<<endl;
	return 0;
}


