#include <fstream>
#include <iostream>
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
	ofstream outfile("l13-11.txt",ios::binary);
	student s[3]={"li",1001,18,'f',"fang",1002,19,'m',"wang",1004,17,'f'};
	if(!outfile)
	{
		cout<<"open error"<<endl;
		abort();
	}
	for(int i=0;i<3;i++)
	{
		cout<<s[i].name<<endl;
		outfile.write((char*)&s[i],sizeof(s[i]));
	}
	outfile.close();
	return 0;
}
