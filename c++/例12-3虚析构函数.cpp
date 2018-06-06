#include <iostream>
using namespace std;
class point
{
public:
	point(){}
	virtual ~point(){cout<<"executing point destructor"<<endl;}
};

class circle:public point
{
public:
	circle(){}
	~circle(){cout<<"executing circle destructor"<<endl;}
private:
	int radus;
};

int main()
{
	point *p=new circle;
	delete p;
	return 0;
}

