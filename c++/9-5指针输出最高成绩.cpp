#include <iostream>
using namespace std;

class student
{
public:
	student(int,double);
	void show();
	friend void max(student *p,student s[5]);
private:
	int num;
	float score;
};

int main()
{
	student s[5]={student(1,87.8),student(2,55.6),student(3,98.4),student(4,65.8),student(5,46.8)};
	student * p;
	p=s;
	max(p,s);
	p->show();
	return 0;
}

student::student(int a,double b):num(a),score(b){};

void student::show()
{
	cout<<"num="<<num<<endl<<"score="<<score<<endl;
}

void max(student *p,student s[5])
{
	int j=0;
	for(int i=1;i<5;i++)
		if(s[j].score<s[i].score)
			j=i;
	*p=*(p+j);
}
