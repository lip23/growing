#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//打开文件
	char *p;
	p=new char [10];
	cout<<"请输入您要打开的文件名称："<<endl;
	cin>>p;
	ifstream infile(p,ios::in);
	if(!infile)
	{
		cout<<"open erro"<<endl;
		exit(1);
	}
	

	//输入要查找的关键字
	char **k;
	int n;
	cout<<"请输入您要查找的关键字的个数："<<endl;
	cin>>n;
	cout<<"请输入您要查找的关键字："<<endl;
	k=new char* [n];
	for(int i=0;i<n;i++)
	{
		k[i]=new char [10];
		cin>>k[i];
	}
	delete []k;


	//关键字的查找
	char *s;
	for(int i=0;!infile.eof();i++)
	{
		s=new char [100];
		infile.getline(s,100,'\n');
		for(int a=0;s[a];a++)
			for(int b=0;b<n;b++)

		delete []s;
	}
	infile.close();
	delete []p;
	
	return 0;
}
