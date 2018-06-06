#include <iostream>
using namespace std;

class time
{
private:
	//int hour;
	int minute;
	int second;
public:
	int hour;
	time(int=0,int=0,int=0);
	void show();
	~time();
};

int main()
{
	time t1;
	t1.show();
	time t2(18,29,56);
	t2.show();
	void (time::*p)();
	p=&time::show;
	int *q;
	q=&t2.hour;
	cout<<*q<<endl;
	time *i;
	i=&t2;
	i->show();
	time t3;
	(t3.*p)();
	return 0;
}

time::time(int h,int m,int s):hour(h),minute(m),second(s){};

time::~time()
{
	cout<<"destroied date"<<endl;
}

void time::show()
{
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}