#include <iostream>
using namespace std;

class time
{
public:
	time(int=0,int=0);
	void show();
	time operator ++();
	time operator ++(int);
private:
	int second;
	int minute;
};

time::time(int s,int m):second(s),minute(m){};

void time::show()
{
	cout<<minute<<":"<<second<<endl;
}

time time::operator ++()
{
	if(second<60)
		second++;
	if(second>=60)
		{
			second=second-60;
			minute++;
		}
	return *this;
}

time time::operator ++(int)
{
	time temp(*this);
	if(++second>=60)
	{
		second-=60;
		minute++;
	}
	return temp;
}

int main()
{
	time t1(33,33),t2;
	t1.show();
	t2=++t1;
	t2.show();
	t1.show();
	t2=t1++;
	t2.show();
	t1.show();
	return 0;
}
