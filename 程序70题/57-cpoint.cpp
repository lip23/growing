#include <iostream>
#include <cmath>
using namespace std;

class point
{
private:
	double x;
	double y;
public:
	point(double=0,double=0);
	point operator + (point &);
	double operator ^ (point &);
	void display();
};

point::point(double a,double b):x(a),y(b){}

point point::operator + (point &p)
{
	return point(x+p.x,y+p.y);
}

double point::operator ^ (point & p)
{
	return double(sqrt((x-p.x)*(x-p.x)+(p.y-y)*(p.y-y)));
}

void point::display()
{
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
}

int main()
{
	point p1(1.2,-3.5),p2(-1.5,6),p3;
	p3=p1+p2;
	p3.display();
	cout<<(p1^p2)<<endl;
	return 0;
}
