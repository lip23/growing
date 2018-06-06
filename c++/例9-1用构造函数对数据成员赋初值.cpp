#include <iostream>
using namespace std;

class time
{
private:
	int hour;
	int minute;
	int second;
public:
	time();
	void set();
	void show();
};

time::time()
{
	hour=0;
	minute=0;
	second=0;
}

void time::set()
{
	cin>>hour>>minute>>second;
}

void time::show()
{
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}

int main()
{
	time t1;
	t1.set();
	t1.show();
	time t2;
	t2.show();
	t2=t1;
	t2.show();
	return 0;
}
