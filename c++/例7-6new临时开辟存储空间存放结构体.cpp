#include <iostream>
#include <string>
using namespace std;

struct student
{
	string num;
	string name;
	float score;
};


int main()
{
	student *p;
	p=new student;
	cin>>p->num>>p->name>>p->score;
	cout<<p->num<<" "<<p->name<<" "<<p->score<<endl;
	return 0;
}
