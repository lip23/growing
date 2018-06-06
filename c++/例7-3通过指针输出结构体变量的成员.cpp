#include <iostream>
using namespace std;

struct student
{
	int num;
	char name[20];
	char sex;
	int grade;
};

student stu={123,"jake",'m',99};


int main()
{
	student *p;
	p=&stu;
	cout<<(*p).grade<<endl<<p->num<<endl;
	cout<<++p->num<<endl;
	return 0;
}
