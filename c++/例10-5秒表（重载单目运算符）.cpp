#include <iostream.h>

class time
{
public:
	time(int=0,int=0);
	void show();
	void operator ++();
private:
	int second;
	int minute;
};

time::time(int s,int m):second(s),minute(m){};

void time::show()
{
	cout<<minute<<":"<<second<<endl;
}

void time::operator ++()
{
	for(int i=1;i<60;i++)
	{
		second++;
		show();
	}
	minute++;
	second=0;
	show();
}

int main()
{
	time t1;
	++t1;
	++t1;
	return 0;
}