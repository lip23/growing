#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int x=1;
	for(int i=1;i<=10;i++)
	{
		cout<<"��"<<setw(2)<<11-i<<"����������ǣ�"<<x<<endl;
		x=2*x+2;
	}
	return 0;
}