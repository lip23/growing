#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int t=0,min=200,max=0,ti,ta;
	char *p;
	char *s;
	p=new char [10];
	cin>>p;
	ifstream infile(p,ios::in);
	ofstream outfile("68bb.txt",ios::out);
	for(int i=1;!infile.eof();i++)
	{
		s=new char [200];
		infile.getline(s,200,'\n');
		if(s[0]!=NULL)
		{
			for(int j=0;s[j+1];j++)
			{
				if(s[j]=='/'&&s[j+1]=='/')
					s[j]='\0';
			}
			if(strlen(s)>max)
			{
				ta=i;
				max=strlen(s);
			}
			if(strlen(s)<min)
			{
				ti=i;
				min=strlen(s);
			}
			outfile<<s<<endl;
			t++;
		}
		delete []s;
	}
	cout<<"minline="<<min<<endl;
	cout<<"i="<<ti<<endl;
	cout<<"maxline="<<max<<endl;
	cout<<"i="<<ta<<endl;
	cout<<"totalline="<<t<<endl;
	infile.close();
	delete []p;
	return 0;
}
	
