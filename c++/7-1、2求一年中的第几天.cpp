#include <iostream>
using namespace std;

struct date
{
	int year;
	int month;
	int day;
};

int main()
{
	date d;
	int m;
	int days(int &,int &,int &);
	cout<<"请输入一个日期：年 月 日"<<endl;
	cin>>d.year;
	cin>>d.month;
	cin>>d.day;
	m=days(d.year,d.month,d.day);
	cout<<m<<endl;
	return 0;
}


int days(int &i,int &j,int &k)
{
	int m=0;
	switch(j-1)
	{
	case 12: m=m+31;
	case 11: m=m+30;
	case 10: m=m+31;
	case 9 : m=m+30;
	case 8 : m=m+31;
	case 7 : m=m+31;
	case 6 : m=m+30;
	case 5 : m=m+31;
	case 4 : m=m+30;
	case 3 : m=m+31;
	case 2 : m=m+28;
	case 1 : m=m+31;
	}
	if(i%4==0&&i%100!=0)
		m=m+1+k;
	else
		m=m+k;
	return m;
}
