#include <iostream>
#include <string>
using namespace std;
int main()
{
	int days1(int);
	int days2(int,int,int);
	string data;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		int year=0,month=0,day=0;
		for(int k=0;data[k]!='-';k++)
			year=year*10+data[k]-48;
		for(k++;data[k]!='-';k++)
			month=month*10+data[k]-48;
		for(k++;data[k];k++)
			day=day*10+data[k]-48;
		int year2=year+18;
		if((month==2&&day==29)&&((year2%4!=0||year2%100==0)&&year2%400!=0))
			cout<<-1<<endl;
		else
		{
			int total=days1(year)+days2(year+18,month,day)+365-days2(year,month,day);
			if((year%4==0&&year%100!=0)||year%400==0)
				total++;
			cout<<total<<endl;
		}
	}
	return 0;
}

int days1(int y)
{
	int total=0;
	for(int i=y+1;i<y+18;i++)
		if((i%4==0&&i%100!=0)||i%400==0)
			total+=366;
		else
			total+=365;
	return total;
}

int days2(int y,int m,int d)
{
	int total=0;
	switch(m-1)
	{
	case 11:total+=30;
	case 10:total+=31;
	case 9:total+=30;
	case 8:total+=31;
	case 7:total+=31;
	case 6:total+=30;
	case 5:total+=31;
	case 4:total+=30;
	case 3:total+=31;
	case 2:total+=28;
	case 1:total+=31;
	};
	if(((y%4==0&&y%100!=0)||y%400==0)&&m>2)
		total++;
	return total+d;
}




