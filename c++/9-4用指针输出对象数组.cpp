#include <iostream>
using namespace std;

class student
{
public:
	student(int,double);
	void show();
private:
	int num;
	float score;
};

int main()
{
	student s[5]={student(1,87.8),student(2,35.6),student(3,98.4),student(4,65.8),student(5,46.8)};
	student * p;
	p=s;
	p->show();
	(p+2)->show();
	(p+4)->show();
	return 0;
}

student::student(int a,double b):num(a),score(b){};

void student::show()
{
	cout<<"num="<<num<<endl<<"score="<<score<<endl;
}