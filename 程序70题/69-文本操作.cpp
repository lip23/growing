#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//���ļ�
	char *p;
	p=new char [10];
	cout<<"��������Ҫ�򿪵��ļ����ƣ�"<<endl;
	cin>>p;
	ifstream infile(p,ios::in);
	if(!infile)
	{
		cout<<"open erro"<<endl;
		exit(1);
	}
	

	//����Ҫ���ҵĹؼ���
	char **k;
	int n;
	cout<<"��������Ҫ���ҵĹؼ��ֵĸ�����"<<endl;
	cin>>n;
	cout<<"��������Ҫ���ҵĹؼ��֣�"<<endl;
	k=new char* [n];
	for(int i=0;i<n;i++)
	{
		k[i]=new char [10];
		cin>>k[i];
	}
	delete []k;


	//�ؼ��ֵĲ���
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
