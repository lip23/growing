#include <iostream>
#include <string>
using namespace std;

struct score
{
	int g1;
	int g2;
	int g3;
};

struct student
{
	string num;
	string name;
	score grade;
};


int main()
{
	student s;
	cout<<"please put student1's num name grade1 grade2 grade 3"<<endl;
	cin>>s.num>>s.name>>s.grade.g1>>s.grade.g2>>s.grade.g3;
	void print1(student);
	cout<<"�ṹ�������������������ʽ���"<<endl<<endl;
	print1(s);
	cout<<"�ýṹ���������ָ���������������"<<endl<<endl;
	void print2(student *);
	print2(&s);
	cout<<"�ýṹ��������������������������"<<endl<<endl;
	void print3(student &);
	print3(s);
	return 0;
}


void print1(student g)
{
	cout<<g.num<<" "<<g.name<<" "<<g.grade.g1<<" "<<g.grade.g2<<" "<<g.grade.g3<<endl<<endl;
}

void print2(student *p)
{
	cout<<p->num<<" "<<(*p).name<<" "<<(*p).grade.g1<<" "<<(*p).grade.g2<<" "<<p->grade.g3<<endl<<endl;
}

void print3(student &g)
{
	cout<<g.num<<" "<<g.name<<" "<<g.grade.g1<<" "<<g.grade.g2<<" "<<g.grade.g3<<endl<<endl;
}


