#include <iostream>
using namespace std;

class date;

class time
{
public:
	friend void display(date d,time t);
	time(int,int,int);
private:
	int hour;
	int minute;
	int second;
};

class date
{
public:
	friend void display(date d,time t);
	date(int,int,int);
private:
	int year;
	int month;
	int day;
};

int main()
{
	date d(2013,2,6);
	time t(17,36,56);
	display(d,t);
	return 0;
}

time::time(int h,int m,int s):hour(h),minute(m),second(s){};

date::date(int y,int m,int d):year(y),month(m),day(d){};

void display(date d,time t)
{
	cout<<d.year<<'/'<<d.month<<'/'<<d.day<<endl;
	cout<<t.hour<<":"<<t.minute<<':'<<t.second<<endl;
}