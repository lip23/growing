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
		cout<<"������ѧ�� "<<i+1<<" ��ѧ�� ���� �ɼ�1 �ɼ�2 �ɼ�3 "<<endl;
		input(s[i]);
	}
	cout<<"�⼸��ѧ���������ǣ�"<<endl;
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