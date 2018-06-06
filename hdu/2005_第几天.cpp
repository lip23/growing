#include <iostream>
#include <string>
#include <numeric>
using namespace std;
int main()
{
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	string data;
	while(cin>>data){
		int year=0,month=0,day=0;
		int k=0;
		while(data[k]!='/')year=year*10+data[k++]-48;
		//cout<<year<<endl;
		while(data[++k]!='/')month=month*10+data[k]-48;
		//cout<<month<<endl;
		while(data[++k])day=day*10+data[k]-48;
		//cout<<day<<endl;
		int total=accumulate(days,days+month-1,day);
		if(month>2&&((year%4==0&&year%100!=0)||year%400==0))++total;
		cout<<total<<endl;
	}
	return 0;
}
