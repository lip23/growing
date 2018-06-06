#include <iostream>
#include <fstream>
using namespace std;

struct student
{
	char name[20];
	int num;
	int age;
	char sex;
};

int main()
{
	ifstream infile("l13-11.txt",ios::in|ios::binary);
	student s[3];
	if(!infile)
	{
		cerr<<"open eroor"<<endl;
		exit(1);
	}
	for(int i=0;i<3;i++)
		infile.read((char*)&s[i],sizeof(s[i]));
	for(i=0;i<3;i++)
	{
		cout<<"no."<<i<<endl;
		cout<<s[i].name<<endl;
		cout<<s[i].num<<endl;
		cout<<s[i].age<<endl;
		cout<<s[i].sex<<endl;
	}
	infile.close();
	return 0;
}
