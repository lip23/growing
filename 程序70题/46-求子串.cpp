#include <iostream>
#include <string>
using namespace std;

int main()
{
	char * str;
	char * sub;
	char * findfirst(char *,char *);
	char * findlast(char *,char *);
	str=new char;
	sub=new char;
	cout<<"请输入一个字符串："<<endl;
	cin>>str;
	cout<<"您输入的字符窜中各字符的地址是："<<endl;
	for(int i=0;str[i];i++)
		cout<<(int)&str[i]<<endl;
	cout<<"请输入您要查询的子串:"<<endl;
	cin>>sub;
	int n=(int)findfirst(str,sub);
	int m=(int)findlast(str,sub);
	if(n==0)
		cout<<"您要查找的子串不在该字符中:"<<endl;
	else
	{
		cout<<"您要查找的子串第一次出现的地址是："<<endl;
		cout<<n<<endl;
		cout<<"您要查找的子串最后一次出现的地址是："<<endl;
		cout<<m<<endl;
	}
	return 0;
}

char * findfirst(char * str,char * sub)
{
	int l1=strlen(str);
	int l2=strlen(sub);
	int m,j,i;
	if(l1<l2)
		return NULL;
	for(i=0;i<l1-l2+1;i++)
	{
		m=i;
		j=0;
		while(str[m]==sub[j])
		{
			m++;
			j++;
			if(j==l2)	
				return &str[i];
		}
	}
	return NULL;
}


char * findlast(char * str,char * sub)
{
	int l1=strlen(str);
	int l2=strlen(sub);
	int m,j,i;
	if(l1<l2)
		return NULL;
	for(i=l1-1;i>=l1-l2-1;i--)
	{
		m=i;
		j=l2-1;
		while(str[m]==sub[j])
		{
			m--;
			j--;
			if(j==-1)	
				return &str[m+1];
		}
	}
	return NULL;
}



	
