#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class datetype
{
public:
	datetype(int=0,int=0,int=0);
	void incrementday();
	bool equal(datetype &);
	void printdate();
	void setdatedype();
	friend int dif(datetype &,datetype &);
	friend int aday(datetype &);
	friend void xingqi(datetype&);
	friend void yueli(datetype&);
private:
	int year;
	int month;
	int day;
};

int main()
{
	int x;
	cout<<setiosflags(ios::left);
	cout<<"��������Ҫִ�еĲ�����"<<'\n'<<"1 �鿴����  2 �鿴���� 3 ��ʱ���� 4 ��n�������� 5 ��ֹ����"<<endl;
	do
	{
		cin>>x;
		if(x==1)
		{
			datetype d1;
			d1.setdatedype();
			d1.printdate();
			cout<<"���·ݵ������ǣ�"<<endl;
			yueli(d1);
			cout<<"��������Ҫִ�еĲ���"<<endl;
		}
		else if(x==2)
		{
			datetype d2;
			d2.setdatedype();
			d2.printdate();
			cout<<"�������ǣ�"<<endl;
			xingqi(d2);
			cout<<"��������Ҫִ�еĲ���"<<endl;
		}
		else if(x==3)
		{
			datetype d1,d2;
			d1.setdatedype();
			d2.setdatedype();
			d1.printdate();
			d2.printdate();
			cout<<"���������ڼ��ʱ�����ǣ�"<<fabs(dif(d1,d2))<<endl;
			cout<<"��������Ҫִ�еĲ���"<<endl;
		}
		else if(x==4)
		{
			int n;
			datetype d1;
			d1.setdatedype();
			d1.printdate();
			cout<<"��������Ҫ����֮������ڣ�"<<endl;
			cin>>n;
			for(int i=0;i<n;i++)
				d1.incrementday();
			cout<<n<<"���������ǣ�"<<endl;
			d1.printdate();
			cout<<"��������Ҫִ�еĲ�����"<<endl;
		}
		else if(x==5)
			cout<<"������ֹ"<<endl;
		else
			cout<<"������Ĳ�����������������"<<endl;
	}while(x!=5);
	return 0;
}

void datetype::setdatedype()//�趨�������գ����ж�����������Ƿ���ȷ
{
	cout<<"������һ�����ڣ���/��/��"<<endl;
	cout<<"��������ݣ�"<<endl;
	cin>>year;
	while(year<0)
	{
		cout<<"�������������������빫Ԫ������"<<endl;
		cin>>year;
	}
	cout<<"�������·ݣ�"<<endl;
	cin>>month;
	while(month<1||month>12)
	{
		cout<<"��������·���������������"<<endl;
		cin>>month;
	}
	cout<<"������������"<<endl;
	cin>>day;
	while(day>31||day<0)
	{
		cout<<"�������������������������"<<endl;
		cin>>day;
	}
	int t;
	if(month==2)
		t=28;
	else if(month==4||month==6||month==11||month==9)
		t=30;
	switch(t)
	{
	case 28:
		{
			if(year%4==0&&year%100!=0||year%400==0)
				while(day>29)
				{
					cout<<"�������������������������"<<endl;
					cin>>day;
				}
			else
				while(day>28)
				{
					cout<<"�������������������������"<<endl;
					cin>>day;
				}
		}break;
	case 30:
		{
			while(day>30)
			{
				cout<<"�������������������������"<<endl;
				cin>>day;
			}
		}break;
	}
}

datetype::datetype(int y,int m,int d):year(y),month(m),day(d){};

void datetype::incrementday()//һ��һ�������
{
	int t;
	if(month==2)
		t=28;
	else if(month==4||month==6||month==11||month==9)
		t=30;
	else if(month==12)
		t=12;
	else
		t=31;
	switch(t)
	{
	case 31:
		{
			if(day==31)
			{
				day=1;
				month++;
			}
			else
				day++;	
		}break;
	case 28:
		{
			if(year%4==0&&year%100!=0||year%400==0)
			{
				if(day==29)
				{
					day=1;
					month++;
				}
				else
					day++;
			}
			else
				if(day==28)
				{
					day=1;
					month++;
				}
				else
					day++;
		}break;
	case 30:
		{
			if(day==30)
			{
				day=1;
				month++;
			}
			else
				day++;	
		}break;
	case 12:
		{
			if(day==31)
			{
				day=1;
				month=1;
				year++;
			}
			else
				day++;
		}
	}
}

bool datetype::equal(datetype & d)//�ж����������Ƿ����
{
	if(year==d.year&&month==d.month&&day==d.day)
		return true;
	else
		return false;
}

void datetype::printdate()//�������
{
	cout<<year<<'/'<<month<<'/'<<day<<endl;
}

int dif(datetype& d1,datetype& d2)//��������֮��ļ��
{
	int ty1,ty2,tj=0;
	int aday(datetype&);
	//int ty1=d1.year,ty2=d2.year,tj=0;
	if(d2.year>=d1.year)
	{
		ty1=d1.year;
		ty2=d2.year;
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
	else
	{
		ty1=d2.year;
		ty2=d1.year;
		for(ty1;ty1<ty2;ty1++)
		{
			if(ty1%4==0&&ty1%100!=0||ty1%400==0)
				tj=tj+366;
			else
				tj=tj+365;
		}
		tj=tj+aday(d1)-aday(d2);
		return -tj;
	}
}

int aday(datetype& d)//ͬһ�����������
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

void xingqi(datetype & d)//�������ڼ�
{
	datetype dc(2013,1,6);
	int jc=dif(dc,d);
	char s[7][10]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
	int t;
	t=jc%7;
	if(t<0)
		t=t+7;
	cout<<s[t]<<endl;
}

void yueli(datetype& d)//�������
{
	char s[7][5]={"sun","mon","tue","wed","thu","fri","sat"};
	for(int i=0;i<7;i++)
		cout<<setw(5)<<s[i];
	cout<<endl;
	d.day=1;
	int y;
	if(d.month==2)
	{
		if(d.year%4==0&&d.year%100!=0||d.year%400==0)
			y=29;
		else
			y=28;
	}
	else if(d.month==4||d.month==6||d.month==11||d.month==9)
		y=30;
	else
		y=31;
	datetype dt(2013,1,6);
	int jc=dif(dt,d);
	int t=jc%7;
	if(t<0)
		t=t+7;
	for(i=0;i<t;i++)
		cout<<setw(5)<<' ';
	for(i=t;i<y+t;i++)
	{
		if(i%7==0)
			cout<<endl;
		cout<<setw(5)<<i+1-t;
	}
	cout<<endl;
}
	
