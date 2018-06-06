#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ofstream outfile("l13-10f2.txt",ios::out);
	if(!outfile)
	{
		cout<<"open error"<<endl;
		exit(1);
	}
	string s;
	cin>>s;
	outfile<<s<<endl;
	outfile.close();
	string s1;
	ifstream infile("l13-10f2.txt",ios::in);
	if(!infile)
	{
		cout<<"open error"<<endl;
		exit(1);
	}
	infile>>s1;
	for(int i=0;s1[i];i++)
	{
		if(s1[i]>=97&&s1[i]<=122)
			s1[i]=s1[i]-32;
	}
	cout<<s1<<endl;
	outfile.open("l13-10f3.txt",ios::out);
	if(!outfile)
	{
		cout<<"open error"<<endl;
		exit(1);
	}
	outfile<<s1<<endl;
	infile.close();
	outfile.close();
	return 0;
}
