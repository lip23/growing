#include <iostream.h>

class point
{
public:
	point(double=0,double=0);
	friend istream & operator >>(istream &,point &);
	friend ostream & operator <<(ostream &,point &);
protected:
	double x;
	double y;
};

point::point(double a,double b)
{
	x=a;
	y=b;
}

istream & operator >>(istream & input,point & p)
{
	cout<<"please input x  y"<<endl;
	input>>p.x>>p.y;
	return input;
}

ostream & operator <<(ostream & output,point & p)
{
	output<<"x="<<p.x<<endl;
	output<<"y="<<p.y<<endl;
	return output;
}

class circle:public point
{
public:
	circle(double=0,double=0,double=0);
	friend istream & operator >>(istream &,circle &);
	friend ostream & operator <<(ostream &,circle &);
protected:
	double r;
};

circle::circle(double a,double b,double c):point(a,b),r(c){}

istream & operator >>(istream &input,circle & c)
{
	cout<<"please input x  y  r"<<endl;
	cin>>c.x>>c.y>>c.r;
	return input;
}

ostream & operator <<(ostream & output,circle & c)
{
	output<<"x="<<c.x<<endl;
	output<<"y="<<c.y<<endl;
	output<<"r="<<c.r<<endl;
	return output;

class cylinder:public circle
{
public:
	cylinder(double=0,double=0,double=0,double=0);
	friend istream & operator >>(istream &,cylinder &);
	friend ostream & operator <<(ostream &,cylinder &);
private:
	double h;
};

cylinder::cylinder(double a,double b,double c,double d):circle(a,b,c)
{
	h=d;
}

istream & operator >>(istream & input,cylinder & c)
{
	cout<<"please input x  y  r  h"<<endl;
	input>>c.x>>c.y>>c.r>>c.h;
	return input;
}

ostream & operator <<(ostream &output,cylinder &c)
{
	output<<"x="<<c.x<<endl;
	output<<"y="<<c.y<<endl;
	output<<"r="<<c.r<<endl;
	output<<"h="<<c.h<<endl;
	return output;
}

int main()
{
	point a;
	cin>>a;
	cout<<a;
	circle b;
	cin>>b;
	cout<<b;
	cylinder e;
	cin>>e;
	cout<<e;
	return 0;
}


