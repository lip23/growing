#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student
{
	int num;
	char name[20];
	double score;
};

int main()
{
	//将5个学生的数据存入文件中；
	int i;
	fstream iofile("l13-13.txt",ios::in|ios::out|ios::binary);
	if(!iofile)
	{
		cerr<<"open error"<<endl;
		exit(1);
	}
	student s[5]={1001,"li",85,1002,"fang",97.5,1004,"wang",54,1005,"tan",76.5,1010,"ling",96};
	for(i=0;i<5;i++)
		iofile.write((char*)&s[i],sizeof(s[i]));
	iofile.seekg(ios::beg);
	//读出1,3,5学生的信息
	for(i=0;i<5;i+=2)
	{
		iofile.read((char*)&s[i],sizeof(s[i]));
		iofile.seekg(sizeof(s[i+1]),ios::cur);
		cout<<"No."<<i+1<<endl;
		cout<<s[i].num<<endl;
		cout<<s[i].name<<endl;
		cout<<s[i].score<<endl;
		cout<<endl;
	}

	//修改第3个学生信息
	s[2].num=1012;
	strcpy(s[2].name,"wu");
	s[2].score=60;
	iofile.seekp(2*sizeof(s[0]),ios::beg);
	iofile.write((char*)&s[2],sizeof(s[2]));

	iofile.seekg(ios::beg);

	cout<<"修改后的学生信息："<<endl;

	for(i=0;i<5;i++)
	{
		iofile.read((char*)&s[i],sizeof(s[i]));
		cout<<"No."<<i+1<<endl;
		cout<<s[i].num<<endl;
		cout<<s[i].name<<endl;
		cout<<s[i].score<<endl;
		cout<<endl;
	}
	iofile.close();
	return 0;
}