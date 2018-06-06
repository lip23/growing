#include <iostream>
using namespace std;

class sail
{
public:
	static void average();
	static void display();
	sail(int,int,double);
	void c();
private:
	static double discout;
	static double sum;
	static double ave;
	static int n;
	int num;
	int quantity;
	double price;
};

int main()
{
	sail s[3]={sail(101,5,23.5),sail(102,12,24.56),sail(103,100,21.5)};
	for(int i=0;i<3;i++)
		s[i].c();
	sail::average();
	sail::display();
	return 0;
}

sail::sail(int n,int q,double p):num(n),quantity(q),price(p){};

 double sail::discout=0.98;

 double sail::sum=0;

 int sail::n=0;

 double sail::ave=0;

void sail::average()
{
	ave=sum/n;
}

void sail::display()
{
	cout<<"sum="<<sum<<endl;
	cout<<"ave="<<ave<<endl;
}

void sail::c()
{
	if(quantity>=10)
		price=price*discout;
	sum=sum+quantity*price;
	n=n+quantity;
}
	