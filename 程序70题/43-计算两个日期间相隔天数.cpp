#include <iostream>
using namespace std;

class daydate
{
public:
	daydate(int=0,int=0,int=0);
	int year;
	int month;
	int day;
};

daydate::daydate(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
}

istream & operator >>(istream & input,daydate &d)
{
	input>>d.year>>d.month>>d.day;
	return input;
}

int main()
{
	int dif(daydate,daydate),j;
	daydate d1,d2;
	cout<<"计算两个日期之间的间隔"<<endl<<endl;
	cout<<"请输入一个日期：年 月 日"<<endl;
	cin>>d1;
	cout<<"请输入另一个日期："<<endl;
	cin>>d2;
	j=dif(d1,d2);
	cout<<j<<endl;
	return 0;
}

int dif(daydate d1,daydate d2)
{
	int ty1=d1.year,ty2=d2.year,tj=0;
	int aday(daydate);
	for(ty1;ty1<ty2;ty1++)
	{
		if(ty1%4==0&&ty1%100!=0||ty1%400==0)
			tj=tj+366;
		else
			tj=tj+365;
	}
	tj=tj+aday(d2)-aday(d1);
	return tj;
}

int aday(daydate d)
{
	int td=0;
	switch(d.month-1)
	{
	case 12:td=td+31;
	case 11:td=td+30;
	case 10:td=td+31;
	case  9:td=td+30;
	case  8:td=td+31;
	case  7:td=td+31;
	case  6:td=td+30;
	case  5:td=td+31;
	case  4:td=td+30;
	case  3:td=td+31;
	case  2:td=td+28;
	case  1:td=td+31;
	}
	if(d.year%4==0&&d.year%100!=0||d.year%400==0)
		td=td+d.day+1;
	else
		td=td+d.day;
	return td;
}

