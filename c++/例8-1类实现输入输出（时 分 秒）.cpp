#include <iostream>
using namespace std;

class time
{
private:
	int hour;
	int minute;
	int second;
public:
	void input();
	void print();
};

void time::input()
{
	cin>>hour>>minute>>second;
}

void time::print()
{
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}

int main()
{
	time t;
	t.input();
	t.print();
	return 0;
}
	