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
	cout<<"������һ���ַ�����"<<endl;
	cin>>str;
	cout<<"��������ַ����и��ַ��ĵ�ַ�ǣ�"<<endl;
	for(int i=0;str[i];i++)
		cout<<(int)&str[i]<<endl;
	cout<<"��������Ҫ��ѯ���Ӵ�:"<<endl;
	cin>>sub;
	int n=(int)findfirst(str,sub);
	int m=(int)findlast(str,sub);
	if(n==0)
		cout<<"��Ҫ���ҵ��Ӵ����ڸ��ַ���:"<<endl;
	else
	{
		cout<<"��Ҫ���ҵ��Ӵ���һ�γ��ֵĵ�ַ�ǣ�"<<endl;
		cout<<n<<endl;
		cout<<"��Ҫ���ҵ��Ӵ����һ�γ��ֵĵ�ַ�ǣ�"<<endl;
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



	
