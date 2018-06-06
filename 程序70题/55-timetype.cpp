#include <iostream>
using namespace std;

class timetype
{
public:
	timetype(int=0,int=0,int=0);
	void incrementsec(int);
	void incrementmin(int);
	void incrementhou(int);
	bool equal(timetype);
	void printtime();
	void settime();
	int jiange(timetype);
	void show();
private:
	int hour;
	int minute;
	int second;
};

void timetype::settime()
{
	cin>>hour>>minute>>second;
}

int timetype::jiange(timetype t)
{
	return int((hour-t.hour)*3600+(minute-t.minute)*60+second-t.second);
}

void timetype::show()
{
	if(hour>12&&hour<=24)
		cout<<hour-12<<':'<<minute<<':'<<second<<" pm"<<endl;
	else if(hour>=0&&hour<=12)
		cout<<hour<<':'<<minute<<':'<<second<<" am"<<endl;
	else if(hour>24&&hour<0)
		cout<<"date erro"<<endl;
}

timetype::timetype(int h,int m,int s):hour(h),minute(m),second(s){};

void timetype::incrementsec(int s)
{
	if(second+s>=60)
	{
		incrementmin((second+s)/60);
		second=(second+s)%60;
	}
	else if(s+second>=0&&s+second<60)
		second=second+s;
	else if(s<0)
		cout<<"date erro"<<endl;
}

void timetype::incrementmin(int m)
{
	if(m+minute>=60)
	{
		incrementhou((m+minute)/60);
		minute=(minute+m)%60;
	}
	else if(m+minute>=0&&m+minute<60)
		minute=minute+m;
	else if(m<0)
		cout<<"date erro"<<endl;
}

void timetype::incrementhou(int h)
{
	if(h+hour>=24)
		hour=(hour+h)%24;
	else if(h+hour<24&&h+hour>0)
		hour=hour+h;
	else if(h<0)
		cout<<"date erro"<<endl;
}

bool timetype::equal(timetype t)
{
	if(second==t.second&&minute==t.minute&&hour==t.hour)
		return true;
	else
		return false;
}

void timetype::printtime()
{
	cout<<hour<<':'<<minute<<':'<<second<<endl;
}

int main()
{
	timetype t1,t2;
	cout<<"请输入t1 t2 的时间："<<endl;
	t1.settime();
	t2.settime();
	cout<<"时间 t1 t2:"<<endl;
	t1.printtime();
	t1.show();
	t2.printtime();
	t2.show();
	int n;
	cout<<"请输入增加的秒数："<<endl;
	cin>>n;
	t1.incrementsec(n);
	t1.show();
	cout<<"判读t1 t2 是否相等："<<endl;
	if(t1.equal(t2))
		cout<<"t1=t2"<<endl;
	else
		cout<<"t1!=t2"<<endl;
	cout<<"t1 t2 相隔的时间是："<<endl;
	cout<<t1.jiange(t2)<<endl;
	return 0;
}


