#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int n=10;
	char a[n][15] = {"guoli","lina","liqi","liuyan","majing","sunlijuan","wangle","wuda","yangke","zhangyifu" };
	int search(char (*p)[15], int n, char*name);
	int i;
	char *name;
	name=new char;
	cout<<"��������Ҫ���ҵ����֣�"<<endl;
	cin>>name;
	int m;
	cout<<"����������ʼ���ҵ�λ�ã�"<<endl;
	cin>>m;
	i=search(a+m-1,n,name);
	if(i==-1)
		cout<<"��Ҫ���ҵ��˲�����"<<endl;
	else
		cout<<"��Ҫ���ҵ��˵�λ��i="<<i+m-1<<endl;
	return 0;
}

int search(char (*p)[15],int n,char *name)
{
	for(int i=0;p[i];i++)
		if(strcmp(p[i],name)==0)
			return i+1;
		else if(i==n-1&&strcmp(p[i],name)!=0)
			return -1;
}
