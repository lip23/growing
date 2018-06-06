#include <iostream>
#include <string>
using namespace std;

struct student
{
	string num;
	string name;
	float score[3];
};


int main()
{
	void input(student &);
	void print(student &);
	student s[3];
	int i;
	for(i=0;i<3;i++)
	{
		cout<<"请输入学生 "<<i+1<<" 的学号 姓名 成绩1 成绩2 成绩3 "<<endl;
		input(s[i]);
	}
	cout<<"这几个学生的数据是："<<endl;
	for(i=0;i<3;i++)
		print(s[i]);
	return 0;
}

void input(student &s)
{
	cin>>s.num>>s.name>>s.score[0]>>s.score[1]>>s.score[2];
}

void print(student &s)
{
	cout<<s.num<<endl;
	cout<<s.name<<endl;
	cout<<s.score[0]<<endl;
	cout<<s.score[1]<<endl;
	cout<<s.score[2]<<endl;
}