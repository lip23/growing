#include <strstream>
#include <iostream>
using namespace std;

struct student
{
	int num;
	char name[20];
	double score;
};

int main()
{
	student s[3]={1001,"li",78,1002,"wang",89.5,1004,"fang",90};
	char c[50];
	ostrstream strout(c,30);
	for(int i=0;i<3;i++)
		strout<<s[i].num<<s[i].name<<s[i].score;
	c[30]='\0';
	cout<<"array c:"<<c<<endl;
	return 0;
}
