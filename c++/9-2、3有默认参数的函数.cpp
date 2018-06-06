#include <iostream>
using namespace std;

class date
{
public:
	date(int=1,int=1,int=2005);
	void display();
private:
	int month;
	int day;
	int year;
};

int main()
{
	date d1;
	d1.display();
	date d2(10);
	d2.display();
	date d3(10,13);
	d3.display();
	date d4(10,13,2006);
	d4.display();
	return 0;
}

date::date(int m,int d,int y):month(m),day(d),year(y){};

void date::display()
{
	cout<<month<<"/"<<day<<"/"<<year<<endl;
}
