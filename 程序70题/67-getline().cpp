#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	
	char *p1;
	p1=new char[10];
	char *p2;
	p2=new char[10];
	cout<<"请输入您要打开的文件1的名字："<<endl;
	cin>>p1;
	ifstream infile(p1,ios::in);
	if(!infile)
	{
		cout<<"open erro"<<endl;
		exit(1);
	}
	cout<<"请输入您要打开的文件2的名字："<<endl;
	cin>>p2;
	ifstream infile2(p2,ios::in);
	if(!infile2)
	{
		cout<<"open erro"<<endl;
		exit(1);
	}	
	char *s1;
	s1=new char [50];
	char *s2;
	s2=new char [50];
	for(int i=1;!infile.eof()&&!infile2.eof();i++)
	{
		infile.getline(s1,50,'\n');
	    infile2.getline(s2,50,'\n');
		if(strcmp(s1,s2)!=0)
		{
			cout<<"第"<<i<<"行"<<endl;
			cout<<s1<<endl;
		    cout<<s2<<endl;
		}
	}
	infile.close();
	infile2.close();
	delete []p1;
	delete []p2;
	delete []s1;
	delete []s2;
	return 0;
}
