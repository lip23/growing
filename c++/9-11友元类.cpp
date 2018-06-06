#include <iostream>
using namespace std;

class time;

class date
{
public:
	void display(time t);
	date(int,int,int);
private:
	int year;
	int month;
	int day;
};

class time
{
public:
	friend class date;
	void display();
	time(int,int,int);
private:
	int hour;
	int minute;
	int second;
};

int main()
{
	date d(2013,2,6);
	time t(20,23,56);
	d.display(t);
	return 0;
}

time::time(int h,int m,int s):hour(h),minute(m),second(s){};

date::date(int y,int m,int d):year(y),month(m),day(d){};

void date::display(time t)
{
	cout<<year<<'/'<<month<<'/'<<day<<endl;
	cout<<t.hour<<":"<<t.minute<<':'<<t.second<<endl;
}